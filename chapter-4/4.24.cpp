// if operands in ?: operator expression combined from left to right
// the epressions would be changed to
// finalgrade = ((grade > 90) ? "high pass" : (grade < 60)) ? "fail" : "pass";
// which would produce an unexpected behaviour, if grade > 90, the first condition's result would be "high pass", then the finalgrade would always be fail
