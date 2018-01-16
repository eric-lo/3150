#!/bin/bash

mynum=3150
course_code="csci"
mystr=${course_code}

# grow mystr from 3150 to "3150?"
echo "Before: ${mystr}"
mystr+=${mynum}
echo "After: ${mystr}"
echo ""

# when curly braces are necessary
echo "${course_code}3150 is a course about OS"
