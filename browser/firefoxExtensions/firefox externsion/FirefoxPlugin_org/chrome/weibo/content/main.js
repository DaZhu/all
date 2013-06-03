function OnWeiboSendMes(event)
{
	var jQ = jQuery.noConflict(); // jQuery obj
	var doc = gBrowser.contentDocument;
	var url = document.commandDispatcher.focusedWindow.document.URL;
	var pic = "";
	var node = document.popupNode;
	
	if(node.nodeName == "A")
	{
		url = node.attributes.href.nodeValue;
	}
	else if(node.nodeName == "IMG")
	{
		pic = node.attributes.src.nodeValue;
	}
	var title = document.title;
	var selectedText = doc.getSelection().toString();
	var send = title + " " + selectedText + "|" + url + "|" + pic;
	send = encodeURI(send);
	var ret = SendMessage(send);
}

function SendMessage(mes)
{
	//alert("in");
    Components.utils.import("resource://gre/modules/ctypes.jsm");
	//alert("import js-ctypes success");
	var profFile = Components.classes["@mozilla.org/file/directory_service;1"]
				.getService(Components.interfaces.nsIProperties)
				.get("ProfD", Components.interfaces.nsIFile);
	var profPath = profFile.path;
	//alert(profFile.path);
	var strDllPath = profPath.concat('\\extensions\\{1B33E42F-EF14-4cd3-B6DC-434571C43491}\\components\\WeiboSendMes_DLL.dll');
	//alert(strDllPath);
	var lib = ctypes.open(strDllPath);
	//alert("dll opened");
	/* Declare the signature of the function we are going to call */
	var SendMes = lib.declare("WeiboSendMessage_DLL",ctypes.winapi_abi,ctypes.bool,ctypes.char.ptr);
	//alert("function build success");
	var ret = SendMes(mes);
	//alert("call function success");
	lib.close();
	return ret;
}