/***********************************************************************
    filename:   CEGUIOpenGLTexture.h
    created:    Wed, 8th Feb 2012
    author:     Lukas E Meindl (based on code by Paul D Turner)
*************************************************************************/
/***************************************************************************
 *   Copyright (C) 2004 - 2012 Paul D Turner & The CEGUI Development Team
 *
 *   Permission is hereby granted, free of charge, to any person obtaining
 *   a copy of this software and associated documentation files (the
 *   "Software"), to deal in the Software without restriction, including
 *   without limitation the rights to use, copy, modify, merge, publish,
 *   distribute, sublicense, and/or sell copies of the Software, and to
 *   permit persons to whom the Software is furnished to do so, subject to
 *   the following conditions:
 *
 *   The above copyright notice and this permission notice shall be
 *   included in all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *   IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 *   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 *   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *   OTHER DEALINGS IN THE SOFTWARE.
 ***************************************************************************/
#ifndef _CEGUIOpenGL3Texture_h_
#define _CEGUIOpenGL3Texture_h_

#include "../../Base.h"
#include "../../Renderer.h"
#include "../../Texture.h"
#include "CEGUI/RendererModules/OpenGL3/Renderer.h"

#if defined(_MSC_VER)
#   pragma warning(push)
#   pragma warning(disable : 4251)
#endif

// Start of CEGUI namespace section
namespace CEGUI
{
//! Texture implementation for the OpenGL3Renderer.
class OPENGL3_GUIRENDERER_API OpenGL3Texture : public Texture
{
public:
    /*!
    \brief
        set the openGL texture that this Texture is based on to the specified
        texture, with the specified size.
    */
    void setOpenGLTexture(GLuint tex, const Sizef& size);

    /*!
    \brief
        Return the internal OpenGL texture id used by this Texture object.

    \return
        id of the OpenGL texture that this object is using.
    */
    GLuint getOpenGLTexture() const;

    /*!
    \brief
        set the size of the internal texture.

    \param sz
        size for the internal texture, in pixels.

    \note
        Depending upon the hardware capabilities, the actual final size of the
        texture may be larger than what is specified when calling this function.
        The texture will never be smaller than what you request here.  To
        discover the actual size, call getSize.

    \exception RendererException
        thrown if the hardware is unable to support a texture large enough to
        fulfill the requested size.

    \return
        Nothing.
    */
    void setTextureSize(const Sizef& sz);

    /*!
    \brief
        Grab the texture to a local buffer.

        This will destroy the OpenGL texture, and restoreTexture must be called
        before using it again.
    */
    void grabTexture();

    /*!
    \brief
        Restore the texture from the locally buffered copy previously create by
        a call to grabTexture.
    */
    void restoreTexture();

    // implement abstract members from base class.
    const String& getName() const;
    const Sizef& getSize() const;
    const Sizef& getOriginalDataSize() const;
    const Vector2f& getTexelScaling() const;
    void loadFromFile(const String& filename, const String& resourceGroup);
    void loadFromMemory(const void* buffer, const Sizef& buffer_size,
                        PixelFormat pixel_format);
    void blitFromMemory(void* sourceData, const Rectf& area);
    void blitToMemory(void* targetData);
    bool isPixelFormatSupported(const PixelFormat fmt) const;

protected:
    // Friends (to allow construction and destruction)
    friend Texture& OpenGL3Renderer::createTexture(const String&);
    friend Texture& OpenGL3Renderer::createTexture(const String&, const String&, const String&);
    friend Texture& OpenGL3Renderer::createTexture(const String&, const Sizef&);
    friend Texture& OpenGL3Renderer::createTexture(const String&, GLuint, const Sizef&);
    friend void OpenGL3Renderer::destroyTexture(Texture&);
    friend void OpenGL3Renderer::destroyTexture(const String&);

    //! Basic constructor.
    OpenGL3Texture(OpenGL3Renderer& owner, const String& name);
    //! Constructor that creates a Texture from an image file.
    OpenGL3Texture(OpenGL3Renderer& owner, const String& name,
                  const String& filename, const String& resourceGroup);
    //! Constructor that creates a Texture with a given size.
    OpenGL3Texture(OpenGL3Renderer& owner, const String& name,
                  const Sizef& size);
    //! Constructor that wraps an existing GL texture.
    OpenGL3Texture(OpenGL3Renderer& owner, const String& name,
                  GLuint tex, const Sizef& size);
    //! Destructor.
    virtual ~OpenGL3Texture();

    //! generate the OpenGL texture and set some initial options.
    void generateOpenGLTexture();

    //! updates cached scale value used to map pixels to texture co-ords.
    void updateCachedScaleValues();

    //! clean up the GL texture, or the grab buffer if it had been grabbed
    void cleanupOpenGLTexture();

    //! initialise the internal format flags for the given CEGUI::PixelFormat.
    void initInternalPixelFormatFields(const PixelFormat fmt);

    //! internal texture resize function (does not reset format or other fields)
    void setTextureSize_impl(const Sizef& sz);

    void loadUncompressedTextureBuffer(const Sizef& buffer_size,
                                       const GLvoid* buffer) const;

    void loadCompressedTextureBuffer(const Sizef& buffer_size,
                                     const GLvoid* buffer) const;

    //! The OpenGL texture we're wrapping.
    GLuint d_ogltexture;
    //! Size of the texture.
    Sizef d_size;
    //! cached image data for restoring the texture.
    uint8* d_grabBuffer;
    //! original pixel of size data loaded into texture
    Sizef d_dataSize;
    //! cached pixel to texel mapping scale values.
    Vector2f d_texelScaling;
    //! OpenGL3Renderer that created and owns this OpenGL3Texture
    OpenGL3Renderer& d_owner;
    //! The name given for this texture.
    const String d_name;
    //! Texture format
    GLenum d_format;
    //! Texture subpixel format
    GLenum d_subpixelFormat;
    //! Whether Texture format is a compressed format
    bool d_isCompressed;
};

} // End of  CEGUI namespace section

#if defined(_MSC_VER)
#   pragma warning(pop)
#endif

#endif // end of guard _CEGUIOpenGLTexture_h_
