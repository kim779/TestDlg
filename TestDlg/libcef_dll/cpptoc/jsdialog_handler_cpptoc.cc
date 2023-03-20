// Copyright (c) 2012 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//

#include "libcef_dll/cpptoc/jsdialog_handler_cpptoc.h"
#include "libcef_dll/ctocpp/browser_ctocpp.h"
#include "libcef_dll/ctocpp/frame_ctocpp.h"


// MEMBER FUNCTIONS - Body may be edited by hand.

int CEF_CALLBACK jsdialog_handler_on_jsalert(
    struct _cef_jsdialog_handler_t* self, cef_browser_t* browser,
    cef_frame_t* frame, const cef_string_t* message) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return 0;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame)
    return 0;
  // Unverified params: message

  // Execute
  bool _retval = CefJSDialogHandlerCppToC::Get(self)->OnJSAlert(
      CefBrowserCToCpp::Wrap(browser),
      CefFrameCToCpp::Wrap(frame),
      CefString(message));

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK jsdialog_handler_on_jsconfirm(
    struct _cef_jsdialog_handler_t* self, cef_browser_t* browser,
    cef_frame_t* frame, const cef_string_t* message, int* retval) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return 0;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame)
    return 0;
  // Verify param: retval; type: bool_byref
  DCHECK(retval);
  if (!retval)
    return 0;
  // Unverified params: message

  // Translate param: retval; type: bool_byref
  bool retvalBool = (retval && *retval)?true:false;

  // Execute
  bool _retval = CefJSDialogHandlerCppToC::Get(self)->OnJSConfirm(
      CefBrowserCToCpp::Wrap(browser),
      CefFrameCToCpp::Wrap(frame),
      CefString(message),
      retvalBool);

  // Restore param: retval; type: bool_byref
  if (retval)
    *retval = retvalBool?true:false;

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK jsdialog_handler_on_jsprompt(
    struct _cef_jsdialog_handler_t* self, cef_browser_t* browser,
    cef_frame_t* frame, const cef_string_t* message,
    const cef_string_t* defaultValue, int* retval, cef_string_t* result) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return 0;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame)
    return 0;
  // Verify param: retval; type: bool_byref
  DCHECK(retval);
  if (!retval)
    return 0;
  // Verify param: result; type: string_byref
  DCHECK(result);
  if (!result)
    return 0;
  // Unverified params: message, defaultValue

  // Translate param: retval; type: bool_byref
  bool retvalBool = (retval && *retval)?true:false;
  // Translate param: result; type: string_byref
  CefString resultStr(result);

  // Execute
  bool _retval = CefJSDialogHandlerCppToC::Get(self)->OnJSPrompt(
      CefBrowserCToCpp::Wrap(browser),
      CefFrameCToCpp::Wrap(frame),
      CefString(message),
      CefString(defaultValue),
      retvalBool,
      resultStr);

  // Restore param: retval; type: bool_byref
  if (retval)
    *retval = retvalBool?true:false;

  // Return type: bool
  return _retval;
}


// CONSTRUCTOR - Do not edit by hand.

CefJSDialogHandlerCppToC::CefJSDialogHandlerCppToC(CefJSDialogHandler* cls)
    : CefCppToC<CefJSDialogHandlerCppToC, CefJSDialogHandler,
        cef_jsdialog_handler_t>(cls) {
  struct_.struct_.on_jsalert = jsdialog_handler_on_jsalert;
  struct_.struct_.on_jsconfirm = jsdialog_handler_on_jsconfirm;
  struct_.struct_.on_jsprompt = jsdialog_handler_on_jsprompt;
}

#ifndef NDEBUG
template<> long CefCppToC<CefJSDialogHandlerCppToC, CefJSDialogHandler,
    cef_jsdialog_handler_t>::DebugObjCt = 0;
#endif

