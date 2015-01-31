<html>
<head><title>Class Demonstration</title>
</head>
<body>
<?php
class Employee
{
     var $name;
	 var $salary;
	 var $designation;
	 
	
	 function Employee($name,$designation,$salary)
	 {
	      $this->name=$name;
		  $this->designation=$designation;
		  $this->salary=$salary;
	 }
	 
	 function setSalary($salary)
	 {
	     $this->salary=$salary;
	 }
	 
	 function getSalary()
	 {
	     return $this->salary;
	 }
	 
     function setName($name)
	 {
	     $this->name=$name;
	 }
	 
	 function getName()
	 {
	     return $this->name;
	 }
	 
	 function setDesignation($designation)
	 {
	     $this->designation=$designation;
	 }
	 
	 function getDesignation()
	 {
	     return $this->designation;
	 }	
	  
	 function printDetails()
	 {
	     print("Name : ".$this->name."<br>");
		 print("Designation: ".$this->designation."<br>");
		 print("Salary : ".$this->salary."<br>");
	 }
	 
}

$emp1=new Employee("Mark","Tester","10000");
$emp1->printDetails();
$emp1->setSalary("40000");
$emp1->setName("John");
$emp1->setDesignation("Analyst");
$emp1->printDetails();
$emp2=new Employee("Andy","Developer","60000");
$emp2->printDetails();
?>
</body>
</html>
