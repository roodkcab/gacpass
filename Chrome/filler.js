chrome.runtime.onMessage.addListener(function (request, sender, sendResponse) {
  let password = $(":password");
  if (password.length > 0) {
    let idx = $("input").toArray().indexOf(password[0]);
    let username = $($("input")[idx - 1]);
    switch (request.cmd) {
      case 'getUsername':
        sendResponse(username.val());
        break;
      case 'fill':
        password.val(request.data.password);
        username.val(request.data.username);
    	let code = $($("input")[idx + 1]);
        if (code && request.data.code) {
          code.val(request.data.code);
        }
        break;
    }
  }
  return true;
});
