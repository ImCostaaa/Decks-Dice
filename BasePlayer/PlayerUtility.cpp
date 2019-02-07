
/**
 * @author Thomas Morphew 250921958
 */

#include "Player.h"

using namespace std;
int main(){
    //Login
    cout << "Login/Constructor Operation" << endl;
    Player *myUser = new Player("Thomas","password");
    cout << "Expected: Thomas,password,200" << endl;
    string out = myUser->getUsername() + "," + myUser->getPassword() + ",";
    out = out + std::to_string(myUser->getBalance());
    cout << out << endl;
    
    Player *myOtherUser = new Player("a","a");
    
    cout << "Expected: ,,500 " << endl;
    out = myOtherUser->getUsername() + "," + myOtherUser->getPassword() + ",";
    out = out + std::to_string(myOtherUser->getBalance());
    cout << out << endl;

    if(myUser->isPseudo()){
        cout << "I am a pseudo" << endl;
    }
    else{
        cout << "I am not a pseudo" << endl;
    }

    if(myOtherUser->isPseudo()){
        cout << "I am a pseudo" << endl;
    }
    else{
        cout << "I am not a pseudo" << endl;
    }


    cout << "Change password" << endl;

    cout << myUser->getPassword() << endl;
    myUser->setPassword("newPass");
    cout << myUser->getPassword() << endl;

    cout << "Highscore Operations" << endl;

    cout << myUser->getHighscore("WAR") << endl;
    myUser->setHighscore("WAR", 100);
    cout << myUser->getHighscore("WAR") << endl;

    
    cout << "Balance operations" << endl;
    
    cout << myUser->getBalance() << endl;
    myUser->setBalance(300);
    cout << myUser->getBalance() << endl;

    cout << "Change Username when it is already in use" << endl;

    cout << myUser->getUsername() << endl;
    myUser->setUsername("Mark");
    cout << "Expected: Thomas" << endl;
    cout << myUser->getUsername() << endl;


    cout << "Change username when it is not in use" <<endl;

    cout << myUser->getUsername() << endl;
    myUser->setUsername("NewUser");
    cout << "Expected: NewUser" << endl;
    cout << myUser->getUsername() << endl;

    cout << "Change username when it is a substring of another" << endl;

    cout << myUser->getUsername() << endl;
    myUser->setUsername("Mat");
    cout << "Expected: Mat" << endl;
    cout << myUser->getUsername() << endl;
    myUser->setPassword("hockey");
    cout << myUser->getPassword() << endl;

    Player *myUser2 = new Player("Mat", "hockey");

    cout << "Last stuff" << endl;

    cout << myUser2->getUsername() << endl;
    cout << myUser2->getBalance() << endl;

    delete myUser;
    delete myOtherUser;
    delete myUser2;
    return 0;
}