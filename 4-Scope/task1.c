/*
    init values:
        int: i; -> starts as a garbage value
        int: j=0;

        i does not get redeclared in loop so its value increments i defined out of the loop scope
        j is initiliazed in the i loop scope so will not be stored out of these loops


    output during loops:
        "Variable i (2) is bigger than j (1)"
        "Variable i (3) is bigger than j (2)"
        "Variable i (4) is bigger than j (3)"
        "Variable i (5) is bigger than j (4)"
        "Variable i (6) is bigger than j (5)"
        "Variable i (7) is bigger than j (6)"
        "Variable i (8) is bigger than j (7)"
        "Variable i (9) is bigger than j (8)"

    output during loops if break wasn't there:
        "Variable i (2) is bigger than j (1)"
        "Variable i (3) is bigger than j (2)"
        "Variable i (3) is bigger than j (1)"
        "Variable i (4) is bigger than j (3)"
        "Variable i (4) is bigger than j (2)"
        "Variable i (4) is bigger than j (1)"
        "Variable i (5) is bigger than j (4)"
        "Variable i (5) is bigger than j (3)"
        "Variable i (5) is bigger than j (2)"
        "Variable i (5) is bigger than j (1)"        
        "Variable i (6) is bigger than j (5)"
        "Variable i (6) is bigger than j (4)"
        "Variable i (6) is bigger than j (3)"
        "Variable i (6) is bigger than j (2)"
        "Variable i (2) is bigger than j (1)" 
        "Variable i (7) is bigger than j (6)"
        "Variable i (7) is bigger than j (5)"
        "Variable i (7) is bigger than j (4)"
        "Variable i (7) is bigger than j (3)"
        "Variable i (7) is bigger than j (2)"
        "Variable i (7) is bigger than j (1)" 
        "Variable i (8) is bigger than j (7)"
        "Variable i (8) is bigger than j (6)"
        "Variable i (8) is bigger than j (5)"
        "Variable i (8) is bigger than j (4)"
        "Variable i (8) is bigger than j (3)"
        "Variable i (8) is bigger than j (2)"
        "Variable i (8) is bigger than j (1)" 
        "Variable i (9) is bigger than j (8)"
        "Variable i (9) is bigger than j (7)"
        "Variable i (9) is bigger than j (6)"
        "Variable i (9) is bigger than j (5)"
        "Variable i (9) is bigger than j (4)"
        "Variable i (9) is bigger than j (3)"
        "Variable i (9) is bigger than j (2)"
        "Variable i (9) is bigger than j (1)" 
    
    output after loops:
        `error j has not been defined`

    output after loops if j was removed:
        "Last values: i (10)";
*/