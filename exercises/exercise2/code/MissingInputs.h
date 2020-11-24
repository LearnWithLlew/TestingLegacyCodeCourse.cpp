#pragma once

class MissingInputs
{
    int selection = 0;

public:
    int getCategory(int selection1)
    {
	    if (selection1 == 5)
	    {
		    return 2;
	    }
	    else
	    {
		    return 1;
	    }
    }

    // Not all inputs passed in
    int getCategory()
    {
	    int selection1 = selection;
        return getCategory(selection1);
    }

    void changeCount()
    {
      srand(0);
      selection = rand();
    }
};
