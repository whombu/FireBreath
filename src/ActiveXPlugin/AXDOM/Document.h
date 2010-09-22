/**********************************************************\ 
Original Author: Richard Bateman (taxilian)

Created:    Sep 21, 2010
License:    Dual license model; choose one of two:
            New BSD License
            http://www.opensource.org/licenses/bsd-license.php
            - or -
            GNU Lesser General Public License, version 2.1
            http://www.gnu.org/licenses/lgpl-2.1.html

Copyright 2010 Facebook, Inc and the Firebreath development team
\**********************************************************/

#ifndef H_AXDOM_DOCUMENT
#define H_AXDOM_DOCUMENT

#include <string>
#include "Win/win_common.h"
#include <atlctl.h>
#include "BrowserObjectAPI.h"
#include "DOM/Document.h"
#include "DOM/Element.h"

namespace AXDOM {

    /**
     * Document - used as Document (which is a shared_ptr)
     *
     * Provides a wrapper around a BrowserObjectAPI * that represents a DOM document
     **/
    class Document : public FB::DOM::Document
    {
    public:
        Document(const FB::JSObject &element, IWebBrowser2 *web);
        virtual ~Document();

    public:
        virtual FB::DOM::WindowPtr getWindow();
        virtual FB::DOM::ElementPtr getElementById(const std::string& elem_id);
        virtual std::vector<FB::DOM::ElementPtr> getElementsByTagName(const std::string& tagName);

    protected:
        CComQIPtr<IWebBrowser> m_webBrowser;
        CComQIPtr<IHTMLDocument2> m_htmlDoc;
    };

};

#endif // H_AXDOM_DOCUMENT