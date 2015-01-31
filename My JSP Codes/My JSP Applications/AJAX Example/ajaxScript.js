// JavaScript Document
var xhr;
function initialize()
{
   if(window.XMLHttpRequest)
   xhr=new window.XMLHttpRequest()
   else
   xhr=new window.ActiveXObject("Microsoft.XMLHTTP");
}

function LoginVerify()
{
initialize();
if(xhr) 
    {
	    var url="loginVerify.jsp?un="+document.form1.txtusername.value+"&pwd="+document.form1.txtpassword.value;
		xhr.open("GET",url,true);
		xhr.onreadystatechange = recieverFunction;
		xhr.send(null);
	}     
}

function recieverFunction()
{
 if(xhr.readyState==4 && xhr.status==200)
   {
       var obj = document.getElementById("messageDiv");
		
		if((xhr.responseText+"")=='valid')
		{
			alert(xhr.responseText);
			obj.innerHTML="Valid User";
			
		}
		if((xhr.responseText+"")=='invalid')
		{
			alert(xhr.responseText);
			obj.innerHTML="Invalid Username/Password";
		}
   }
}

var count=0;
var tid;
 function startCounter()
 {
	 window.setInterval("increment()",1000);
 }
 
 function increment()
 {
     var counterObj=document.getElementById("counterDiv");
	 count++;
	 counterObj.innerHTML=count;
 }