/************************************************************************
    filename:   FalSystemButton.cpp
    created:    Sat Jul 9 2005
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
#include "FalSystemButton.h"

// Start of CEGUI namespace section
namespace CEGUI
{
    const utf8 FalagardSystemButton::TypeName[] = "Falagard/SystemButton";

    FalagardSystemButton::FalagardSystemButton(const String& type) :
        FalagardButton(type)
    {
    }

    Rect FalagardSystemButton::getPixelRect(void) const
    {
        // clip to grand-parent as needed
        if (d_window->getParent() && d_window->getParent()->getParent() && d_window->isClippedByParent())
        {
            return d_window->getParent()->getParent()->getInnerRect().getIntersection(d_window->getUnclippedPixelRect());
        }
        // clip to screen if no grand-parent, or if clipping has been disabled for us.
        else
        {
            return System::getSingleton().getRenderer()->getRect().getIntersection(d_window->getUnclippedPixelRect());
        }
    }

} // End of  CEGUI namespace section