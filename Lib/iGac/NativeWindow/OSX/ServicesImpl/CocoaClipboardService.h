//
//  CocoaClipboardService.h
//  GacOSX
//
//  Created by Robert Bu on 12/9/14.
//  Copyright (c) 2014 Robert Bu. All rights reserved.
//

#ifndef __GAC_OSX_COCOA_CLIPBOARD_SERVICE_H__
#define __GAC_OSX_COCOA_CLIPBOARD_SERVICE_H__

#include "GacUI.h"

namespace vl {
    
    namespace presentation {
        
        namespace osx {
            
            class CocoaClipboardService: public Object, public INativeClipboardService
            {
            public:
                Ptr<INativeClipboardReader>		ReadClipboard();
                Ptr<INativeClipboardWriter>		WriteClipboard();
            };
            
        }
    }
}


#endif
