/**
 **************************************************************************
 
 %%                            Basic strategy                            %%
 
 **************************************************************************
 */

/**
 * BasicStrategy is a repository of methods for playing the basic strategy.
 */

using namespace std;

class BasicStrategy{
public:
    BasicStrategy() {};
    // Value of the rank, for soft or hard hand.
    int value(const char &, const bool &);
    // If stand for hard hand of given size, value, against dealer upcard.
    // We also need the first two player's cards to make sure it stands
    // with 7-7 against dealer's 10.
    bool hard_stand(const int &,const int &, const char &, const char &,
                    const char &);
    // If stand for soft hand of given value, against dealer upcard.
    bool soft_stand(const int &, const char &);
    // If double down for given hard hand, against dealer upcard.
    bool hard_double_down(const vector<char> & , const char &);
    // If doouble down for given soft hand, against dealer upcard.
    bool soft_double_down(const vector<char> & , const char &);
    // If split a pair.
    bool split_pair(const char &, const char &);
};

int BasicStrategy::value(const char & rank, const bool & soft){
    if(rank=='A'&&soft)
        return 11;
    if(rank=='A'&&!soft)
        return 1;
    if(rank>='2'&&rank<='9'){
        int v=rank-'0';
        return v;
    }
    return 10;
}

bool BasicStrategy::hard_stand(const int & player_hand_size,
                               const int & hand_value,
                               const char & dealer_upcard,
                               const char & player_1,
                               const char & player_2){
    if(dealer_upcard=='T'&&hand_value==16){
        if(player_hand_size==2)
            return false;
        return true;
    }
    switch(dealer_upcard){
        case '2' :
            if(hand_value>=13)
                return true;
            return false;
            break;
        case '3' :
            if(hand_value>=13)
                return true;
            return false;
            break;
        case '4' :
            if(hand_value>=12)
                return true;
            return false;
            break;
        case '5' :
            if(hand_value>=12)
                return true;
            return false;
            break;
        case '6' :
            if(hand_value>=12)
                return true;
            return false;
            break;
        case '7' :
            if(hand_value>=17)
                return true;
            return false;
            break;
        case '8' :
            if(hand_value>=17)
                return true;
            return false;
            break;
        case '9' :
            if(hand_value>=17)
                return true;
            return false;
            break;
        case 'T' :
            if(hand_value>=17||(player_1==player_2&&hand_value==14))
                return true;
            return false;
            break;
        case 'A' :
            if(hand_value>=17)
                return true;
            return false;
            break;
    }
    return false;
}

bool BasicStrategy::soft_stand(const int & hand_value,
                               const char & dealer_upcard){
    switch(dealer_upcard){
        case '2' :
            if(hand_value>=18)
                return true;
            return false;
            break;
        case '3' :
            if(hand_value>=18)
                return true;
            return false;
            break;
        case '4' :
            if(hand_value>=18)
                return true;
            return false;
            break;
        case '5' :
            if(hand_value>=18)
                return true;
            return false;
            break;
        case '6' :
            if(hand_value>=18)
                return true;
            return false;
            break;
        case '7' :
            if(hand_value>=18)
                return true;
            return false;
            break;
        case '8' :
            if(hand_value>=18)
                return true;
            return false;
            break;
        case '9' :
            if(hand_value>=19)
                return true;
            return false;
            break;
        case 'T' :
            if(hand_value>=19)
                return true;
            return false;
            break;
        case 'A' :
            if(hand_value>=18)
                return true;
            return false;
            break;
    }
    return false;
}

bool BasicStrategy::hard_double_down(const vector<char> & hand,
                                     const char & dealer){
    int player_total=0;
    for(auto card : hand)
        player_total+=value(card,false);
    switch(player_total){
        case 8 :
            if((dealer=='5'||dealer=='6')&&(hand[0]!='2'&&hand[1]!='2'))
                return true;
            break;
        case 9 :
            if(dealer>='2'&&dealer<='6')
                return true;
            break;
        case 10 :
            if(dealer>='2'&&dealer<='9')
                return true;
            break;
        case 11 :
            return true;
            break;
    }
    return false;
}

bool BasicStrategy::soft_double_down(const vector<char> & hand,
                                     const char & dealer){
    if(hand[0]!='A'&&hand[1]!='A')
        return false;
    int ace_index=0;
    if(hand[1]=='A')
        ace_index=1;
    int other_index=(ace_index+1)%2;
    switch(hand[other_index]){
        case 'A' :
            if(dealer=='5'||dealer=='6')
                return true;
            else
                return false;
            break;
        case '2' :
            if(dealer>='4'&&dealer<='6')
                return true;
            else
                return false;
            break;
        case '3' :
            if(dealer>='4'&&dealer<='6')
                return true;
            else
                return false;
            break;
        case '4' :
            if(dealer>='4'&&dealer<='6')
                return true;
            else
                return false;
            break;
        case '5' :
            if(dealer>='4'&&dealer<='6')
                return true;
            else
                return false;
            break;
        case '6' :
            if(dealer>='2'&&dealer<='6')
                return true;
            else
                return false;
            break;
        case '7' :
            if(dealer>='3'&&dealer<='6')
                return true;
            else
                return false;
        break;
    }
    return false;
}

bool BasicStrategy::split_pair(const char & player, const char & dealer){
    switch(player){
        case('A') :
            return true;
            break;
        case('2') :
            if(dealer>='2'&&dealer<='7')
                return true;
            return false;
            break;
        case('3') :
            if(dealer>='2'&&dealer<='7')
                return true;
            return false;
            break;
        case('4') :
            if(dealer=='5')
                return true;
            return false;
            break;
        case('5') :
            return false;
            break;
        case('6') :
            if(dealer>='2'&&dealer<='7')
                return true;
            return false;
            break;
        case('7') :
            if(dealer>='2'&&dealer<='8')
                return true;
            return false;
            break;
        case('8') :
            return true;
            break;
        case('9') :
            if((dealer>='2'&&dealer<='6')||dealer=='8'||dealer=='9')
                return true;
            return false;
            break;
        case('T') :
            return false;
            break;
    }
    return false;
}
