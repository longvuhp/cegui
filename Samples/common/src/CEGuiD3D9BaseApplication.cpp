/************************************************************************
    filename:   CEGuiD3D9BaseApplication.cpp
    created:    24/9/2004
    author:     Paul D Turner
*************************************************************************/
/*************************************************************************
    Crazy Eddie's GUI System (http://www.cegui.org.uk)
    Copyright (C)2004 - 2005 Paul D Turner (paul@cegui.org.uk)
 
    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.
 
    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.
 
    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*************************************************************************/
#include "CEGuiD3D9BaseApplication.h"

#include <d3d9.h>
#include <dinput.h>
// undefine Microsoft macro evilness
#undef min
#undef max

#include "renderers/directx9GUIRenderer/d3d9renderer.h"
#include "CEGuiSample.h"
#include "Win32AppHelper.h"
#include "CEGUI.h"
#include <stdexcept>

/*************************************************************************
    Impl struct
*************************************************************************/
struct CEGuiBaseApplicationImpl
{
    HWND d_window;
    LPDIRECT3D9 d_D3D;
    LPDIRECT3DDEVICE9 d_3DDevice;
    D3DPRESENT_PARAMETERS d_ppars;
    CEGUI::DirectX9Renderer* d_renderer;
    CEGUI::System* d_GuiSystem;
    Win32AppHelper::DirectInputState d_directInput;
};


/*************************************************************************
    Constructor.
*************************************************************************/
CEGuiD3D9BaseApplication::CEGuiD3D9BaseApplication() :
        pimpl(new CEGuiBaseApplicationImpl),
        d_lastTime(GetTickCount()),
        d_frames(0),
        d_FPS(0)
{
    if (pimpl->d_window = Win32AppHelper::createApplicationWindow(800, 600))
    {
        if (initialiseDirect3D(800, 600, D3DADAPTER_DEFAULT, true))
        {
            if (Win32AppHelper::initialiseDirectInput(pimpl->d_window, pimpl->d_directInput))
            {
                pimpl->d_renderer = new CEGUI::DirectX9Renderer(pimpl->d_3DDevice, 3000);

                // initialise the gui system
                pimpl->d_GuiSystem = new CEGUI::System(pimpl->d_renderer);

                CEGUI::Logger::getSingleton().setLoggingLevel(CEGUI::Informative);

                return;
            }

            // cleanup direct 3d systems
            pimpl->d_3DDevice->Release();
            pimpl->d_D3D->Release();
        }

        DestroyWindow(pimpl->d_window);
    }
    else
    {
        MessageBox(0, Win32AppHelper::CREATE_WINDOW_ERROR, Win32AppHelper::APPLICATION_NAME, MB_ICONERROR|MB_OK);
    }

    throw std::runtime_error("Win32 DirectX 9 application failed to initialise.");
}


/*************************************************************************
    Destructor.
*************************************************************************/
CEGuiD3D9BaseApplication::~CEGuiD3D9BaseApplication()
{
    Win32AppHelper::mouseLeaves();

    // cleanup gui system
    delete pimpl->d_GuiSystem;
    delete pimpl->d_renderer;

    Win32AppHelper::cleanupDirectInput(pimpl->d_directInput);

    // cleanup direct 3d systems
    pimpl->d_3DDevice->Release();
    pimpl->d_D3D->Release();

    DestroyWindow(pimpl->d_window);

    delete pimpl;
}


/*************************************************************************
    Start the base application
*************************************************************************/
bool CEGuiD3D9BaseApplication::execute(CEGuiSample* sampleApp)
{
    sampleApp->initialiseSample();

    //
    //  This is basically a modified Win32 message pump
    //
    bool idle;
    HRESULT coop;

    while (Win32AppHelper::doWin32Events(idle))
    {
        if (idle)
        {
            // handle D3D lost device stuff
            coop = pimpl->d_3DDevice->TestCooperativeLevel();

            if (coop == D3DERR_DEVICELOST)
            {
                Sleep(500);
                continue;
            }
            else if (coop == D3DERR_DEVICENOTRESET)
            {
                if (!resetDirect3D())
                {
                    continue;
                }
            }

            if (FAILED(pimpl->d_3DDevice->BeginScene()))
            {
                continue;
            }

            updateFPS();
            char fpsbuff[16];
            sprintf(fpsbuff, "FPS: %d", d_FPS);

            Win32AppHelper::doDirectInputEvents(pimpl->d_directInput);

            // draw display
            pimpl->d_3DDevice->Clear(0, 0, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
            pimpl->d_GuiSystem->renderGUI();

            // render FPS:
            const CEGUI::Font* fnt = pimpl->d_GuiSystem->getDefaultFont();
            if (fnt)
            {
                pimpl->d_GuiSystem->getRenderer()->setQueueingEnabled(false);
                fnt->drawText(fpsbuff, CEGUI::Vector3(0, 0, 0), pimpl->d_GuiSystem->getRenderer()->getRect());
            }

            pimpl->d_3DDevice->EndScene();

            pimpl->d_3DDevice->Present(0, 0, 0, 0);
        }
    }

    return true;
}


/*************************************************************************
    Performs any required cleanup of the base application system.
*************************************************************************/
void CEGuiD3D9BaseApplication::cleanup()
{
    // nothing to do here.
}


/*************************************************************************
    Initialise Direct3D system.
*************************************************************************/
bool CEGuiD3D9BaseApplication::initialiseDirect3D(unsigned int width, unsigned int height, unsigned int adapter, bool windowed)
{
    pimpl->d_D3D = Direct3DCreate9(D3D_SDK_VERSION);

    // display error and exit if D3D creation failed
    if (pimpl->d_D3D)
    {
        D3DDISPLAYMODE d3ddm;
        pimpl->d_D3D->GetAdapterDisplayMode(adapter, &d3ddm);

        D3DFORMAT format = d3ddm.Format;

        // complete window initialisation
        ShowWindow(pimpl->d_window, SW_NORMAL);
        UpdateWindow(pimpl->d_window);

        ZeroMemory(&pimpl->d_ppars, sizeof(pimpl->d_ppars));
        pimpl->d_ppars.BackBufferFormat = format;
        pimpl->d_ppars.hDeviceWindow    = pimpl->d_window;
        pimpl->d_ppars.SwapEffect       = D3DSWAPEFFECT_DISCARD;
        pimpl->d_ppars.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
        pimpl->d_ppars.Windowed         = windowed;

        if (!windowed)
        {
            pimpl->d_ppars.BackBufferWidth          = width;
            pimpl->d_ppars.BackBufferHeight         = height;
            pimpl->d_ppars.BackBufferCount          = 1;
            pimpl->d_ppars.MultiSampleType          = D3DMULTISAMPLE_NONE;
            pimpl->d_ppars.FullScreen_RefreshRateInHz       = D3DPRESENT_RATE_DEFAULT;
        }

        if (SUCCEEDED(pimpl->d_D3D->CreateDevice(adapter, D3DDEVTYPE_HAL, pimpl->d_window, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pimpl->d_ppars, &pimpl->d_3DDevice)))
        {
            return true;
        }
        else
        {
            MessageBox(0, Win32AppHelper::CREATE_DEVICE_ERROR, Win32AppHelper::APPLICATION_NAME, MB_ICONERROR|MB_OK);
        }

        pimpl->d_D3D->Release();
        pimpl->d_D3D = 0;
    }
    else
    {
        MessageBox(0, Win32AppHelper::CREATE_D3D_ERROR, Win32AppHelper::APPLICATION_NAME, MB_ICONERROR|MB_OK);
    }

    return false;
}


/*************************************************************************
    Do reset of Direct3D device
*************************************************************************/
bool CEGuiD3D9BaseApplication::resetDirect3D(void)
{
    // perform ops needed prior to reset
    pimpl->d_renderer->preD3DReset();

    if (SUCCEEDED(pimpl->d_3DDevice->Reset(&pimpl->d_ppars)))
    {
        // re-build stuff now reset has been done.
        pimpl->d_renderer->postD3DReset();

        return true;
    }

    return false;
}