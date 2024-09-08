**1. Problem** <br>
Event който да има дата, начален час, краен час и статично име.
<br>
***Hint:*** Heavy task. Event should be with 2 public constructors (one with const&, one with all the params). Date and Time class are used from outside. The only validation in the Event class should be if the start date is b/n end date(if it isnt just std::swap). 
Date -> unsigned day, months, year (bool is Valid, good()) 
Time -> unsigned secondFormMidnight (validate time in one method)
