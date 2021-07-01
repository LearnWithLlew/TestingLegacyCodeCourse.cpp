#pragma once

class MissingInputs
{
    int selection = 0;

public:
    // Not all inputs passed in
    int getCategory()
    {
        return GetCategory2( selection );
    }

    int GetCategory2( int selection ) const
    {
        if ( selection == 5 )
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }

    void changeCount()
    {
        srand( 0 );
        selection = rand();
    }
};
