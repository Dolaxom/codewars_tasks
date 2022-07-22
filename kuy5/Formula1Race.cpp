#include <string>
#include <vector>
#include <iostream>

void InitArray(std::vector<int>& vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        vec.at(i) = i + 1;
    }
}

int FindPlace(std::vector<int>& vec, int index)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == index)
            return i;
    }

    return -1;
}

void RacerIncident(std::vector<int>& vec, int index)
{
    int tmp = index;
    int pos = FindPlace(vec, index);
    unsigned long strVec = vec.size();
    for (unsigned long i = pos; i < strVec; i++)
    {
        if (i != strVec - 1)
            vec.at(i) = vec[i + 1];
    }
    
    vec.at(strVec - 1) = tmp;
}

void Overtaking(std::vector<int>& vec, int index)
{
    int pos = FindPlace(vec, index);
    int tmp1 = vec[pos], tmp2 = vec[pos - 1];
    vec.at(pos) = tmp2;
    vec.at(pos - 1) = tmp1;
}

int ChampionRank(int champion, const std::string &events)
{
    int place = -1;
    std::vector<int> racers(20);
    
    InitArray(racers);
    std::string tmpStringToInt;
    
    for (int i = 0; i < events.length(); i++)
    {
        if (events[i] == ' ')
            continue;
            
        tmpStringToInt = " ";
        int indexRacerInEvent = 0;
        int j = 0;
        while (events[i] != ' ')
        {
            tmpStringToInt[j] = events[i];
            i++;
            j++;
        }
        
        indexRacerInEvent = std::stoi(tmpStringToInt);
        
        i++;
        int pos = FindPlace(racers, indexRacerInEvent);
        if (events[i] == 'O')
        {
            Overtaking(racers, indexRacerInEvent);
        }
            
        if (events[i] == 'I')
        {
            if (indexRacerInEvent == champion)
                return -1;

            RacerIncident(racers, indexRacerInEvent);            
        }

    }
    
    place = FindPlace(racers, champion) + 1;
    return place;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << ChampionRank(10, "1 I 10 O 2 I"); // 7
}