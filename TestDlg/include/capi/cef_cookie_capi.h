// Copyright (c) 2012 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//

#ifndef CEF_INCLUDE_CAPI_CEF_COOKIE_CAPI_H_
#define CEF_INCLUDE_CAPI_CEF_COOKIE_CAPI_H_
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "include/capi/cef_base_capi.h"


///
// Structure used for managing cookies. The functions of this structure may be
// called on any thread unless otherwise indicated.
///
typedef struct _cef_cookie_manager_t {
  ///
  // Base structure.
  ///
  cef_base_t base;

  ///
  // Set the schemes supported by this manager. By default only "http" and
  // "https" schemes are supported. Must be called before any cookies are
  // accessed.
  ///
  void (CEF_CALLBACK *set_supported_schemes)(struct _cef_cookie_manager_t* self,
      cef_string_list_t schemes);

  ///
  // Visit all cookies. The returned cookies are ordered by longest path, then
  // by earliest creation date. Returns false (0) if cookies cannot be accessed.
  ///
  int (CEF_CALLBACK *visit_all_cookies)(struct _cef_cookie_manager_t* self,
      struct _cef_cookie_visitor_t* visitor);

  ///
  // Visit a subset of cookies. The results are filtered by the given url
  // scheme, host, domain and path. If |includeHttpOnly| is true (1) HTTP-only
  // cookies will also be included in the results. The returned cookies are
  // ordered by longest path, then by earliest creation date. Returns false (0)
  // if cookies cannot be accessed.
  ///
  int (CEF_CALLBACK *visit_url_cookies)(struct _cef_cookie_manager_t* self,
      const cef_string_t* url, int includeHttpOnly,
      struct _cef_cookie_visitor_t* visitor);

  ///
  // Sets a cookie given a valid URL and explicit user-provided cookie
  // attributes. This function expects each attribute to be well-formed. It will
  // check for disallowed characters (e.g. the ';' character is disallowed
  // within the cookie value attribute) and will return false (0) without
  // setting the cookie if such characters are found. This function must be
  // called on the IO thread.
  ///
  int (CEF_CALLBACK *set_cookie)(struct _cef_cookie_manager_t* self,
      const cef_string_t* url, const struct _cef_cookie_t* cookie);

  ///
  // Delete all cookies that match the specified parameters. If both |url| and
  // values |cookie_name| are specified all host and domain cookies matching
  // both will be deleted. If only |url| is specified all host cookies (but not
  // domain cookies) irrespective of path will be deleted. If |url| is NULL all
  // cookies for all hosts and domains will be deleted. Returns false (0) if a
  // non- NULL invalid URL is specified or if cookies cannot be accessed. This
  // function must be called on the IO thread.
  ///
  int (CEF_CALLBACK *delete_cookies)(struct _cef_cookie_manager_t* self,
      const cef_string_t* url, const cef_string_t* cookie_name);

  ///
  // Sets the directory path that will be used for storing cookie data. If
  // |path| is NULL data will be stored in memory only. Returns false (0) if
  // cookies cannot be accessed.
  ///
  int (CEF_CALLBACK *set_storage_path)(struct _cef_cookie_manager_t* self,
      const cef_string_t* path);
} cef_cookie_manager_t;


///
// Returns the global cookie manager. By default data will be stored at
// CefSettings.cache_path if specified or in memory otherwise.
///
CEF_EXPORT cef_cookie_manager_t* cef_cookie_manager_get_global_manager();

///
// Creates a new cookie manager. If |path| is NULL data will be stored in memory
// only. Returns NULL if creation fails.
///
CEF_EXPORT cef_cookie_manager_t* cef_cookie_manager_create_manager(
    const cef_string_t* path);


///
// Structure to implement for visiting cookie values. The functions of this
// structure will always be called on the IO thread.
///
typedef struct _cef_cookie_visitor_t {
  ///
  // Base structure.
  ///
  cef_base_t base;

  ///
  // Method that will be called once for each cookie. |count| is the 0-based
  // index for the current cookie. |total| is the total number of cookies. Set
  // |deleteCookie| to true (1) to delete the cookie currently being visited.
  // Return false (0) to stop visiting cookies. This function may never be
  // called if no cookies are found.
  ///
  int (CEF_CALLBACK *visit)(struct _cef_cookie_visitor_t* self,
      const struct _cef_cookie_t* cookie, int count, int total,
      int* deleteCookie);
} cef_cookie_visitor_t;


#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_CEF_COOKIE_CAPI_H_
