#include <iostream>
#include <vector>
#include <stack>

void Init()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main()
{
    Init();

    std::string Input;
    std::cin >> Input;

    std::stack<char> Stack;

    for (int i = 0; i < Input.size(); i++)
    {
        Stack.push(Input[i]);

        if (Stack.size() >= 4 && Input[i] == 'P')
        {
            std::string Str = "";
            for (int j = 0; j < 4; j++)
            {
                Str.push_back(Stack.top());
                Stack.pop();
            }

            if(Str == "PAPP")
            {
                Str = "P";
            }

            for (int j = Str.size() - 1; j >= 0; j--)
            {
                Stack.push(Str[j]);
            }
        }
    }

    if (Stack.size() == 1 && Stack.top() == 'P')
    {
        std::cout << "PPAP";
    }
    else
    {
        std::cout << "NP";
    }

    return 0;
}