/************************************************************************
	filename: 	WLSliderThumb.h
	created:	10/8/2004
	author:		Paul D Turner
*************************************************************************/
/*************************************************************************
    Crazy Eddie's GUI System (http://crayzedsgui.sourceforge.net)
    Copyright (C)2004 Paul D Turner (crayzed@users.sourceforge.net)

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
#ifndef _WLSliderThumb_h_
#define _WLSliderThumb_h_

#include "WLModule.h"
#include "elements/CEGUIThumb.h"
#include "CEGUIWindowFactory.h"


// Start of CEGUI namespace section
namespace CEGUI
{
/*!
\brief
	Thumb class as used in the WindowsLook Slider.
*/
class WINDOWSLOOK_API WLSliderThumb : public Thumb
{
public:
	/*************************************************************************
		Constants
	*************************************************************************/
	// Image names
	static const utf8	ImagesetName[];				//!< Name of the imageset to use for rendering.
	static const utf8	NormalImageName[];			//!< Name of the image to use for normal rendering.
	static const utf8	HighlightImageName[];		//!< Name of the image to use for hover / highlighted rendering.
	static const utf8	MouseCursorImageName[];		//!< Name of the image used for the mouse cursor.


	/*************************************************************************
		Construction / Destruction
	*************************************************************************/
	WLSliderThumb(const String& type, const String& name);
	virtual ~WLSliderThumb(void);


protected:
	/*************************************************************************
		Implementation Rendering Functions
	*************************************************************************/
	/*!
	\brief
		render the thumb in the normal state.
	*/
	virtual void	drawNormal(float z);

	/*!
	\brief
		render the thumb in the hover / highlighted state.
	*/
	virtual void	drawHover(float z);

	/*!
	\brief
		render the thumb in the pushed state.
	*/
	virtual void	drawPushed(float z)		{drawHover(z);}

	/*!
	\brief
		render the thumb in the disabled state
	*/
	virtual void	drawDisabled(float z);


	/*************************************************************************
		Implementation Data
	*************************************************************************/
	const Image*	d_normalImage;			//!< Image to render in normal state
	const Image*	d_highlightImage;		//!< Image to render in highlighted state.
};


/*!
\brief
	Factory class for producing WLSliderThumb objects
*/
class WINDOWSLOOK_API WLSliderThumbFactory : public WindowFactory
{
public:
	/*************************************************************************
		Construction and Destruction
	*************************************************************************/
	WLSliderThumbFactory(void) : WindowFactory((utf8*)"WindowsLook/SliderThumb") { }
	~WLSliderThumbFactory(void){}


	/*!
	\brief
		Create a new Window object of whatever type this WindowFactory produces.

	\param name
		A unique name that is to be assigned to the newly created Window object

	\return
		Pointer to the new Window object.
	*/
	Window*	createWindow(const String& name);


	/*!
	\brief
		Destroys the given Window object.

	\param window
		Pointer to the Window object to be destroyed.

	\return
		Nothing.
	*/
	virtual void	destroyWindow(Window* window)	 { if (window->getType() == d_type) delete window; }
};

} // End of  CEGUI namespace section


#endif	// end of guard _WLSliderThumb_h_