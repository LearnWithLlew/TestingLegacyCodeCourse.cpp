#pragma once

class MissingInputs
{
    int count = 0;

public:
    // Not all inputs passed in
    int getCategory()
    {
        if (count == 5)
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
};
