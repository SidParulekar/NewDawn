#include <iostream>
#include <ctime>
using namespace std;

void gameStory()
{
  cout<<"PROLOGUE: \n";
  cout <<"-----> A long time ago there was an empire ruled by a council of pure evil that thrived by preying on the weak and downtrodden. Everyone called them the Obscurum (the darkness that plagued the country land). \n\n\n";

  cout<<"-----> It was a dark time where free will of choice was only a luxury belonging to the few in power.\n\n\n";

cout<<"-----> For the empire the most important resource was people. The ones who they could use to tend to their farms and do their dirty work.\n\n\n";

cout<<"-----> So they would pillage and raid neighbouring villages and smaller kingdoms leaving a wake of destruction and grief in the process. And the survivors who had lost everything would be used as slaves.\n\n\n";

  cout<<"-----> However the empire failed to take one thing into consideration. Their actions may have the ability to break the spirits of some but would also result in creating a new spirit of strength and resistance.\n\n\n";

  cout<<"-----> The empire did not know it yet but they had given birth to their worst nightmare. That nightmare was named Orien which means 'a new dawn'. \n\n\n";

cout<<"-----> Orien vowed to bring a change to his country by uniting all who had been a victim to the Obscurum's atrocities, forming a new regime of his own. A regime of change, of resistance, of hope, of freedom.\n\n\n";

cout<<"<----------------------------------------------------------------->\n\n";

}

class Player
{
  private:
  int health=100;
  int orien_critical_hit;
  int orien_defense;
  int max_damage=35;
  int min_damage=20;
  int max_heal=45;
  int min_heal=25;

  public: 
  Player(int oc, int od)
  {
    orien_critical_hit=oc;
    orien_defense=od;

    cout<<"\nORIEN:\n";
    cout<<"<-------------------------------------------------------------->\n";
    cout<<"\nYou will be playing as Orien. Orien is the fearless leader of the resistance. He is the one who will vanquish the Obscurum and lead the way to a new dawn. \n\n";
    cout<<"Orien's Health: "<<health<<endl;
    cout<<"Orien's normal hit attack power is between "<<max_damage<<" and "<<min_damage<<endl;
    cout<<"Orien's critical hit Attack Power: "<<orien_critical_hit<<endl;
    cout<<"Orien's healing capability is between "<<max_heal<<" and "<<min_heal<<endl;
    cout<<"Orien's Defense Power: "<<orien_defense<<endl;
    cout<<"\n<-------------------------------------------------------------->\n"<<endl;
  }

  int GetHealth()
  {
    return health;
  }

  void TakeDamage(int damageToInflict, char stance)
  {
    if(stance=='D' or stance=='d')
    {
       cout<<"\nOrien has taken the defensive stance!";
        if(damageToInflict<=orien_defense)
        {
          cout<<"\nOrien has blocked incoming damage of: "<< damageToInflict<<endl;
          damageToInflict=0;
        }

        else
        {
          cout<<"\nOrien has blocked incoming damage of: "<<     
   orien_defense<<endl;
          damageToInflict = damageToInflict - orien_defense; 
        }
        
    }
    cout<<"\nOrien has taken damage of "<<damageToInflict<<endl;
    if(health>=damageToInflict)
    {
        health = health - damageToInflict;
        cout<<"Orien's Health after taking damage: "<<health<<"\n"<<endl;
        if(health==0)
        {
            cout<<"Orien is dead! Game Over."<<endl;
        }
    }

    else 
    {
        health=0;
        cout<<"Orien Health after taking damage: "<<health<<"\n"<<endl;
        cout<<"Orien is dead! Game Over."<<endl;
    } 

  }

  void Heal()
  {
    srand(time(0));
    int randomHeal=(rand()%(max_heal-min_heal+1)+min_heal);

    if((100-health)>=randomHeal)
      {
          health = health + randomHeal;
      }

      else
      {
          health = 100;
      }

    cout<<"Health potion used!\n";
    cout<<"Orien has increased his health by "<<randomHeal<<" HP.\n";
    cout<<"Orien's health after healing: "<<health<<" HP.\n"<<endl;

  }

  int GiveDamage()
  {
    srand(time(0));
    int randomDamage=(rand()%(max_damage-min_damage+1)+min_damage);

    if(randomDamage%3==0)
      {
        cout<<"\nOrien has dealt a critical hit!"<<endl;
        randomDamage=orien_critical_hit;
      }

    return randomDamage;
  }

~Player(){}

};

class Enemy
{
  private:
  int health=100;
  int umbra_critical_hit;
  int max_damage=40;
  int min_damage=15;

  public:
  Enemy(int uc)
  {
    umbra_critical_hit=uc;
    cout<<"UMBRA:\n";
    cout<<"<-------------------------------------------------------------->\n";
    cout<<"\nObscurum has attacked a nearby village to draw out Orien. Umbra, the leader of Obscurum will be facing Orien himself. Umbra must be stopped! \n\n";
    cout<<"Umbra's Health: "<<health<<endl;
    cout<<"Umbra's normal hit attack power is between "<<max_damage<<" and "<<min_damage<<endl;
    cout<<"Umbra's's critical hit Attack Power: "<<umbra_critical_hit<<endl;
    cout<<"Umbra's's critical hit Attack Power: "<<umbra_critical_hit<<endl;
    cout<<"\n<-------------------------------------------------------------->"<<endl;

  }

  int GetHealth()
  {
    return health;
  }

  void TakeDamage(int damageToInflict)
  {
    cout<<"\nUmbra has taken damage of "<<damageToInflict<<endl;
    if(health>=damageToInflict)
    {
        health = health - damageToInflict;
        cout<<"Umbra's Health after taking damage: "<<health<<"\n"<<endl;
        if(health==0)
        {
            cout<<"Umbra has been defeated! Game Over. Orien has triumphed!"<<endl;
        }
    }

    else 
    {
        health=0;
        cout<<"Umbra's Health after taking damage: "<<health<<"\n"<<endl;
        cout<<"Umbra has been defeated! Game Over. Orien has triumphed!"<<endl;
    } 

  }

  int GiveDamage()
  {
    srand(time(0));
    int randomDamage=(rand()%(max_damage-min_damage+1)+min_damage);

    if(randomDamage%5==0)
    {
      cout<<"\nUmbra has dealt a critical hit!"<<endl;
      randomDamage=umbra_critical_hit;
    }

    return randomDamage;
  }

  ~Enemy(){}

};

int main() 
{
  gameStory();
  char userInput;
 
  do
    {
      Player orien(40,20);
      Enemy umbra(45);
      cout<<"\nCONTROLS:\n";
      cout<<"<-------------------------------------------------------------->\n";
      cout<<"\nPress 'A' or 'a' to attack.\nPress 'H' or 'h' to heal.\nPress 'D' or 'd' to take defensive stance (Defensive Stance can only be used once).\n\n";
       cout<<"<-------------------------------------------------------------->\n";
      cout<<"\nPress S to start the game! OR any other key to exit.\n";

      cin>>userInput;
      
      char PlayerAction;
      int def=0;
      
      if(userInput=='S' || userInput=='s')
      {
        cout<<"--------------------------------------------------------------\n";
        cout<<"\n----> Umbra: So you finally decided to crawl out of your hole! Your courage is acknowledged. Alas it will not help in keeping you alive!\n";
        cout<<"\n----> Orien: I am here to put an end to your crimes and to free my nation from your evil grasp! I would much rather choose to die on my own terms than choose to live without. But much to your unhappiness I am not the one who will be dying today!\n";
        cout<<"\n----> Umbra: HA! We shall see about that!\n\n";
        cout<<"--------------------------------------------------------------\n";
        do
        {
          cout<<"\nHEALTH STATUS:\n";
          cout<<"--------------------------------------------------------------\n";
          cout<<"\nOrien's current health: "<<orien.GetHealth()<<" HP\n"<<endl;
          cout<<"Umbra's current health: "<<umbra.GetHealth()<<" HP\n"<<endl;
          cout<<"--------------------------------------------------------------\n";

          cout<<"\nBATTLE STATUS:\n";
          cout<<"--------------------------------------------------------------\n";
          cout<<"\nEnter what action Orien should take:\n";
          cin>>PlayerAction;
          cout<<"\n";
          if(PlayerAction=='A' || PlayerAction=='a')
          {
            int OrienDamage = orien.GiveDamage();
            cout<<"Orien has attacked and dealt damage of: "<<OrienDamage<<endl;
            umbra.TakeDamage(OrienDamage);
          }

          else if(PlayerAction=='H' || PlayerAction=='h')
          {
            orien.Heal();
          }

          else if(PlayerAction=='D' || PlayerAction=='d')
          {
            if(def<1)
            {
              def++;
            }
            else
            {
              cout<<"\nYou have already used your defensive stance once. Please select another action."<<endl;
              continue;
            }
          }

          else{
            cout<<"Invalid Input.\n";
            continue;
          }

          if(orien.GetHealth()!=0 && umbra.GetHealth()!=0)
          {
            cout<<"\nOrien is about to get attacked!\n";
            int UmbraDamage = umbra.GiveDamage();
            cout<<"Umbra has attacked and dealt damage of: "<<UmbraDamage<<endl;
            orien.TakeDamage(UmbraDamage, PlayerAction);
          }

          cout<<"--------------------------------------------------------------\n";
        }while(orien.GetHealth()>0 && umbra.GetHealth()>0);

      }

    }while(userInput=='S' || userInput=='s');

    cout<<"Thanks for playing!";

}