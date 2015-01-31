function PrintFrame(FrameName)
{
      var Frame=window.frames[FrameName];
      if(Frame)
      {
          Frame.focus();
          Frame.print();
      }
        
 }
function PrintThisPage()
{
	 PrintElementWithCSS('PrintContent','');
}
function PrintWithCSS(css)
{
     PrintElementWithCSS('PrintContent',css);
}
function PrintElement(EId)
{
     PrintElementWithCSS(EId,'');
}
function PrintElementWithCSS(EId,css)
{
       // alert(EId);
	   var sWinHTML ='';var sHeadingHTML = '';
	   if(document.getElementById(EId)!=null)
	  {
		    sWinHTML = document.getElementById(EId).innerHTML;	
	  }
      if(document.getElementById('headingContent')!=null)
	  {
		    sHeadingHTML = document.getElementById('headingContent').innerHTML;
	  }
	     
	  var CSSPath= new Array();
	  CSSPath[0]='/Portal/Headers/NewPortalStyles.css';
	  CSSPath[1]='/Portal/headers/mpstyles_en-US.css';
	  //CSSPath[1]='/Portal/Headers/OldPortalStyles.css';
	  if(css!='')
	  {
	    CSSPath[2]=css;
	  }
	  	    CSSPath[0]=css;
	  PrintContent(sHeadingHTML,sWinHTML,CSSPath);
	    
}

function PrintContent(sHeadingHTML,sWinHTML,CSSPath)
{
     var sOption="toolbar=yes,location=no,directories=yes,menubar=yes,scrollbars=yes,left=100,top=25";
	 var winprint=window.open("","",sOption);
	 var CSSContent='';
	            
	            for (var tempI = 0; tempI < CSSPath.length; tempI++)
                {
                   CSSContent=CSSContent+'<link href="'+CSSPath[tempI]+'" rel="Stylesheet" />';
                }
	 
	 
	 	           // winprint.document.write('<link href="/Portal/Headers/OldPortalStyles.css" rel="Stylesheet" /><link href="/Portal/Headers/NewPortalStyles.css" rel="Stylesheet" /><body>');
	            var Content='<html>';
	            Content =Content+'<head>'+CSSContent+'</head>';
	            Content =Content+'<body>'+'<table align=center>'+'<tr><td>' + sHeadingHTML + '</td></tr>';
	            Content =Content+'<tr><td>' + sWinHTML + '</td></tr>';
	            Content =Content+'</table>';
	            Content =Content+'</body>';
	            Content =Content+'</html>';
	            
	    winprint.document.open();
	           winprint.document.write(Content);
	    winprint.document.close();
	    
	    winprint.focus();
	    winprint.print();
	    winprint.close();

}

//function PrintThisPageWithCount(from)
//{
//	var newWindow = window.open("./print.asp?from="+from, "printWindow", "width=10, height=10");
//	newWindow.close();
//	PrintThisPage();
//}
