<html >
<head>

<title>Inheritance and Overriding</title>
</head>

<body>
<?php
class BaseClass
{
     function sayHello()
	 {
	      print("Hello from Base<br>");
	 }
	 
	 function sayGoodBye()
	 {
	      print("GoodBye from Base<br>");
	 }
}
class DerivedClass extends BaseClass  //Inheritance
{
     function sayGoodMorning()
	 {
	      print("Good Morning from Derived<br>");
	 }
	 function sayHello()   //Overriding
	 {
         BaseClass::sayHello();	      
         print("Hello from Derived<br>");
	 }
}

$d1=new DerivedClass();
$d1->sayGoodBye();
$d1->sayHello();
$b1=new BaseClass();
$b1->sayHello();
?>
</body>
</html>
