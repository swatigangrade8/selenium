// Copyright 2011 WebDriver committers
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef WEBDRIVER_IE_MOUSEDOUBLECLICKCOMMANDHANDLER_H_
#define WEBDRIVER_IE_MOUSEDOUBLECLICKCOMMANDHANDLER_H_

#include "interactions.h"
#include "Session.h"

namespace webdriver {

class MouseDoubleClickCommandHandler : public CommandHandler {
public:
	MouseDoubleClickCommandHandler(void) {
	}

	virtual ~MouseDoubleClickCommandHandler(void) {
	}

protected:
	void MouseDoubleClickCommandHandler::ExecuteInternal(const IESessionWindow& session, const LocatorMap& locator_parameters, const ParametersMap& command_parameters, Response * response) {
		BrowserHandle browser_wrapper;
		int status_code = session.GetCurrentBrowser(&browser_wrapper);
		if (status_code != SUCCESS) {
			response->SetErrorResponse(status_code, "Unable to get current browser");
		}

		HWND browser_window_handle = browser_wrapper->GetWindowHandle();

		// This will never work. There needs to be a doubleClickAt function added 
		// to the webdriver-interactions module.
		clickAt(browser_window_handle, session.last_known_mouse_x(), session.last_known_mouse_y(), MOUSEBUTTON_LEFT);
		clickAt(browser_window_handle, session.last_known_mouse_x(), session.last_known_mouse_y(), MOUSEBUTTON_LEFT);
		response->SetResponse(SUCCESS, Json::Value::null);
	}
};

} // namespace webdriver

#endif // WEBDRIVER_IE_MOUSEDOUBLECLICKCOMMANDHANDLER_H_
