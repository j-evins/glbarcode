//  RendererSvg.hpp
//
//  Copyright (C) 2013-2026  Jaye Evins <evins@snaught.com>
//
//  This file is part of glbarcode++.
//
//  glbarcode++ is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  glbarcode++ is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with glbarcode++.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef glbarcode_RendererSvg_hpp
#define glbarcode_RendererSvg_hpp


#include "Renderer.hpp"


namespace glbarcode
{

        /**
         * @class RendererSvg RendererSvg.h glbarcode/RendererSvg.h
         *
         * Simple SVG Renderer.
         *
         * Renders Scalable Vector Graphics format to stdout.
         */
        class RendererSvg : public Renderer
        {
        public:
                /**
                 * Default Constructor (output goes to stdout).
                 */
                RendererSvg();


                /**
                 * Constructor with output filename
                 */
                RendererSvg( const std::string& filename );


                /**
                 * Copy Constructor
                 */
                RendererSvg( const RendererSvg& from );


                /**
                 * Destructor
                 */
                virtual ~RendererSvg();


                /** Assignment operator.
                 *
                 * @param[in] from The value to assign to this object.
                 *
                 * @return A reference to this object.
                 */
                RendererSvg& operator=( const RendererSvg& from );


                /** Get "filename" parameter
                 *
                 * @returns filename parameter
                 */
                std::string filename( void ) const;


                /** Set "filename" parameter
                 *
                 * @param[in] filename new value of the output filename
                 *
                 * @returns reference to this RendererSvg object for parameter chaining
                 */
                RendererSvg& setFilename( const std::string& filename );


        private:
                /*
                 * Virtual methods implemented by SVG renderer.
                 */
                void drawBegin( double w, double h ) override;;
                void drawEnd( void ) override;;
                void drawLine( double x, double y, double w, double h ) override;;
                void drawBox( double x, double y, double w, double h ) override;;
                void drawText( double x, double y, double size, const std::string& text, HAlign halign = H_ALIGN_CENTER ) override;;
                void drawRing( double x, double y, double r, double w ) override;;
                void drawHexagon( double x, double y, double h ) override;;


        private:
                /**
                 * Private data for SVG Renderer
                 */
                struct PrivateData;
                PrivateData *d;
        };

}

#endif // glbarcode_RendererSvg_hpp
