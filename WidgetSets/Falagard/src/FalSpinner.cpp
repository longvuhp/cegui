/************************************************************************
    filename:   FalSpinner.cpp
    created:    Tue Jul 5 2005
    author:     Paul D Turner <paul@cegui.org.uk>
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
#include "FalSpinner.h"
#include "falagard/CEGUIFalWidgetLookManager.h"
#include "falagard/CEGUIFalWidgetLookFeel.h"
#include "CEGUIWindowManager.h"
#include "elements/CEGUIPushButton.h"
#include "elements/CEGUIEditbox.h"

// Start of CEGUI namespace section
namespace CEGUI
{
    const utf8 FalagardSpinner::WidgetTypeName[] = "Falagard/Spinner";

    FalagardSpinner::FalagardSpinner(const String& type, const String& name) :
        Spinner(type, name)
    {
    }

    FalagardSpinner::~FalagardSpinner()
    {
    }

    void FalagardSpinner::populateRenderCache()
    {
        // get WidgetLookFeel for the assigned look.
        const WidgetLookFeel& wlf = WidgetLookManager::getSingleton().getWidgetLook(d_lookName);
        // try and get imagery for the approprite state.
        const StateImagery* imagery = &wlf.getStateImagery(d_enabled ? "Enabled" : "Disabled");
        // peform the rendering operation
        imagery->render(*this);
    }

    PushButton* FalagardSpinner::createIncreaseButton(const String& name) const
    {
        // return component created by look'n'feel assignment.
        return static_cast<PushButton*>(WindowManager::getSingleton().getWindow(name));
    }

    PushButton* FalagardSpinner::createDecreaseButton(const String& name) const
    {
        // return component created by look'n'feel assignment.
        return static_cast<PushButton*>(WindowManager::getSingleton().getWindow(name));
    }

    Editbox* FalagardSpinner::createEditbox(const String& name) const
    {
        // return component created by look'n'feel assignment.
        return static_cast<Editbox*>(WindowManager::getSingleton().getWindow(name));
    }

    //////////////////////////////////////////////////////////////////////////
    /*************************************************************************

        Factory Methods

    *************************************************************************/
    //////////////////////////////////////////////////////////////////////////
    Window* FalagardSpinnerFactory::createWindow(const String& name)
    {
        return new FalagardSpinner(d_type, name);
    }

    void FalagardSpinnerFactory::destroyWindow(Window* window)
    {
        if (window->getType() == d_type)
            delete window;
    }

} // End of  CEGUI namespace section