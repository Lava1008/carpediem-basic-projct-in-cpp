#include <iostream>
#include <fstream>
#include <string>

using namespace std;
float retrievWeightFromFile(string);
float retrievheightfromfile(string ); 
class friendsNode {
public:
    string userId;
    float weight;
    friendsNode* left;
    friendsNode* right;
    friendsNode(){
    }
    friendsNode(string id, float w) : userId(id), weight(w), left(nullptr), right(nullptr) {}
};

class friendsWeightTree {
private:
    friendsNode* root;

    friendsNode* insertIntoTree(friendsNode* node, string userId, float weight) {
        if (node == nullptr) {
            return new friendsNode(userId, weight);
        }

        if (weight < node->weight) {
            node->left = insertIntoTree(node->left, userId, weight);
        } else {
            node->right = insertIntoTree(node->right, userId, weight);
        }

        return node;
    }


public:
    friendsWeightTree() : root(nullptr) {}

    void insert(string userId, float weight) {
        root = insertIntoTree(root, userId, weight);
    }

    void displayWeight(friendsNode *root){
        if(!root) return;
        displayWeight(root->left);
        cout<<"UserID ="<<root->userId<<"  Weight = "<<root->weight<<endl;
        displayWeight(root->right);
    }
   void display(){
    displayWeight(root);
   }
};

void friendsData(){
    int n , i =1; 
    string self;
    float sweight;
    cout<<"enter no of friends you want to commpare with "<<endl ;
    cin>>n ; 
    friendsWeightTree callfriend ; 
     cout<<"Enter Your UserId:";
     cin>>self;
      sweight=retrievWeightFromFile(self);
      callfriend.insert(self, sweight);
    while(n--){
        string userIdFriends ;
        cout<<"Enter"<<i++<<"Freind UserId";
        cin>>userIdFriends ; 
        float fweight;
        fweight=retrievWeightFromFile(userIdFriends);
        callfriend.insert(userIdFriends,fweight);
    }
    callfriend.display();
}
class freindNodeHeight {
public:
    string userId;
    float height;
    freindNodeHeight* left;
    freindNodeHeight* right;
    freindNodeHeight(){
    }
    freindNodeHeight(string id, float w) : userId(id), height(w), left(nullptr), right(nullptr) {}
};

class friendsheightTree {
private:
    freindNodeHeight* root;

    freindNodeHeight* insertIntoTree(freindNodeHeight* node, string userId, float height) {
        if (node == nullptr) {
            return new freindNodeHeight(userId, height);
        }

        if (height < node->height) {
            node->left = insertIntoTree(node->left, userId, height);
        } else {
            node->right = insertIntoTree(node->right, userId, height);
        }

        return node;
    }


public:
    friendsheightTree() : root(nullptr) {}

    void insert(string userId, float height) {
        root = insertIntoTree(root, userId, height);
    }

    void displayheight(freindNodeHeight *root){
        if(!root) return;
        displayheight(root->left);
        cout<<"UserID ="<<root->userId<<"  height = "<<root->height<<endl;
        displayheight(root->right);
    }
   void display(){
    displayheight(root);
   }
};

void friendsDataHeight(){
    int n , i =1; 
    string self;
    float sheight;
    cout<<"enter no of friends you want to commpare with "<<endl ;
    cin>>n ; 
    friendsheightTree callfriend ; 
     cout<<"Enter Your UserId:";
     cin>>self;
      sheight=retrievheightfromfile(self);
      callfriend.insert(self, sheight);
    while(n--){
        string userIdFriends ;
        cout<<"Enter"<<i++<<"Freind UserId";
        cin>>userIdFriends ; 
        float fheight;
        fheight=retrievheightfromfile(userIdFriends);
        callfriend.insert(userIdFriends,fheight);
    }
    callfriend.display();
}
// Function to check if user exists
bool checkUserExists(string userId) 
{
    ifstream file(userId + ".txt");
    return file.good();
}

// Function to register a new user
void registerUser()
{
    string name, age, gender, userId, height, weight, password;

    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter your gender (M/F): ";
    cin >> gender;

    cout << "Enter your user ID: ";
    cin >> userId;

    if (checkUserExists(userId))
    {
        cout << "User with ID " << userId << " already exists. Please try a different ID." << endl;
        return;
    }

    cout << "Enter your height (in cm): ";
    cin >> height;

    cout << "Enter your weight (in kg): ";
    cin >> weight;

    cout << "Set a password: ";
    cin >> password;

    // Create a text file for the new user
   
    ofstream file(userId + ".txt");
    file << name << endl;
    file << age << endl;
    file << gender << endl;
    file << userId << endl;
    file << height << endl;
    file << weight << endl;
    file << password << endl;
    file.close();
    // ofstream file("allUserWeight.txt") ; 
    // file<<userId <<endl ;
    // file<<weight<<endl ; 
    // cout << "User registration successful!" << endl;
}
// Function to log in an existing user

string loginUserWithoutPassword()
{
    string userId, password;

    cout << "Enter your ID: ";
    cin >> userId;

    if (!checkUserExists(userId))
    {
        cout << "User with ID " << userId << " does not exist." << endl;
    }

    // Read user data from the corresponding text file
    ifstream file(userId + ".txt");
    string line;

    getline(file, line); // Name
    string name = line;

    getline(file, line); // Age
    string ageString = line;
    int age = stoi(ageString);

    getline(file, line); // Gender
    string gender = line;

    getline(file, line); // User ID (skip)

    getline(file, line); // Height
    string heightString = line;
    float height = stof(heightString);

    getline(file, line); // Weight
    string weightString = line;
    float weight = stof(weightString);

    getline(file, line); // Password (skip)
    file.close();
    return userId;
    // Calculate BMI
}
// float CalculateBMI(float height  , float weight){
//  float bmi = weight / (height * height / 10000);
float calculateBMI2(float weight, string userid)
{
    ifstream file(userid + ".txt");
    string line;

    getline(file, line); // Name
    string name = line;

    getline(file, line); // Age
    string ageString = line;
    int age = stoi(ageString);

    getline(file, line); // Gender
    string gender = line;

    getline(file, line); // User ID (skip)

    getline(file, line); // Height
    string heightString = line;
    float height = stof(heightString);

    getline(file, line); // Weight
    string weightString = line;
    weight = stof(weightString);

    getline(file, line); // Password (skip)

    float bmi = weight / (height * height / 10000);

    file.close();
    cout << "Welcome, " << name << "!" << endl;
    cout << "Your BMI is: " << bmi << endl;

    if (bmi < 18.5)
    {
        cout << "You are underweight." << endl;
    }
    else if (bmi >= 18.5 && bmi <= 24.9)
    {
        cout << "You are in the normal weight range." << endl;
    }
    else if (bmi >= 25 && bmi <= 29.9)
    {
        cout << "You are overweight." << endl;
    }
    else
    {
        cout << "You are obese." << endl;
    }
    return bmi;
}
float calculateBMI(float weight , string userid)
{
   
    checkUserExists(userid) ;
    ifstream file(userid + ".txt");
    string line;
    getline(file, line); // Name
    string name = line;
    getline(file, line); // Age
    string ageString = line;
    int age = stoi(ageString);

    getline(file, line); // Gender
    string gender = line;

    getline(file, line); // User ID (skip)

    getline(file, line); // Height
    string heightString = line;
    float height = stof(heightString);

    getline(file, line); // Weight skip
    // string weightString = line;
    //  weight = stof(weightString);

    getline(file, line); // Password (skip)

    float bmi = weight / (height * height / 10000);

    file.close();
    return bmi;
    }
class Node
{
public:
    float data;
    Node *next;

    Node(float value) : data(value), next(nullptr) {}
};
class WeightLinkedList
{
public:
    Node *head;

    WeightLinkedList() : head(nullptr) {}

    void insert(float weight)
    {
        Node *new_node = new Node(weight);
        new_node->next = head;
        head = new_node;
    }
};
void takeAndStoreWeight(WeightLinkedList &weightList)
{
    float weightInput;
    cout << "Enter the weight: ";

    cin >> weightInput;
    weightList.insert(weightInput);
    cout << "Weight " << weightInput << " added to the data tracker." << endl;
}
void bmiForEachWeight(const WeightLinkedList &weightList ,string userid)
{
    Node *currentNode = weightList.head;
    float arr[3];
    int i = 0;
    while (currentNode)
    {
        float weight = currentNode->data;
        currentNode = currentNode->next;
        // cout<<"while loop chala"<<endl ;
        arr[i] = calculateBMI(weight, userid);
        // cout<<" calculatebmi chala"<<endl;
        i++;
    }
    cout << "Your BMI for last 3 weight traces that you have done is " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " "
             << "for weight " << i + 1 << " "<<endl;
        // cout<<"for looop chala"<<endl;
    }
}
void ShowWorkoutPlan(float bmi)
{
 cout << "Workout Guidelines According to BMI:" << endl;

    if(bmi<18.5){
    cout << "\nFor your BMI" <<bmi<<"(Underweight):" << endl;
    cout << "- Goals:" << endl;
    cout << "  - Increase overall strength and muscle mass." << endl;
    cout << "  - Focus on a balanced workout routine." << endl;
    cout << "- Workout Routine:" << endl;
    cout << "  - Strength training: Include compound exercises like squats, deadlifts, bench press, and overhead press." << endl;
    cout << "  - Cardiovascular exercise: Aim for moderate-intensity cardio, such as brisk walking or cycling, to improve cardiovascular health." << endl;
    cout << "  - Frequency: 3-5 days per week." << endl;
    }
    // For BMI Between 18.5 and 24.9 (Normal Weight)
    else if(bmi>=18.5 && bmi< 24.9){
       cout << "\nFor your BMI" <<bmi<<"(Normal Weight):" << endl;
     cout << "- Goals:" << endl;
    cout << "  - Maintain overall health and fitness." << endl;
    cout << "  - Include a mix of cardiovascular and strength training." << endl;
    cout << "- Workout Routine:" << endl;
    cout << "  - Strength training: Include a combination of resistance exercises for major muscle groups." << endl;
    cout << "  - Cardiovascular exercise: Engage in a variety of activities such as running, swimming, or cycling." << endl;
    cout << "  - Flexibility and mobility exercises: Incorporate stretching and mobility work." << endl;
    cout << "  - Frequency: 3-5 days per week." << endl;
    }
    // For BMI Between 25 and 29.9 (Overweight)
    else if(bmi>=24.925 && bmi<29.9){
    cout << "\nFor your BMI" <<bmi<<"(Overweight):" << endl;
    cout << "- Goals:" << endl;
    cout << "  - Focus on fat loss and building lean muscle." << endl;
    cout << "  - Incorporate a combination of strength training and cardiovascular exercise." << endl;
    cout << "- Workout Routine:" << endl;
    cout << "  - Strength training: Include both resistance and bodyweight exercises." << endl;
    cout << "  - High-intensity interval training (HIIT): Integrate bursts of intense exercise with periods of rest." << endl;
    cout << "  - Cardiovascular exercise: Combine aerobic activities with interval training." << endl;
    cout << "  - Frequency: 4-6 days per week." << endl;
}
    // For BMI 30 and Above (Obese)
    else if (bmi>=29.9){
        cout << "\nFor your BMI" <<bmi<<"(Obese):" << endl;
    cout << "- Goals:" << endl;
    cout << "  - Emphasize fat loss, cardiovascular health, and overall well-being." << endl;
    cout << "  - Gradually increase exercise intensity." << endl;
    cout << "- Workout Routine:" << endl;
    cout << "  - Strength training: Incorporate a mix of resistance exercises with an emphasis on full-body workouts." << endl;
    cout << "  - Cardiovascular exercise: Include both steady-state and interval training for effective fat burning." << endl;
    cout << "  - Low-impact activities: Consider activities like swimming or cycling to reduce stress on joints." << endl;
    cout << "  - Frequency: 4-6 days per week." << endl;}

}

void ShowDietPlanAge(int age ){
       if (age < 18) {
        cout << "For your age "<<age<<"(under 18 years old), it's important to prioritize a well-balanced diet with age-appropriate nutritional needs." << endl;
    } else if (age >= 18 && age < 65) {
        cout << "For your age "<<age<< "(18-64 years), maintain a balanced diet and engage in regular physical activity for overall health." << endl;
    } else {
        cout << "For your age "<<age<<" (65 years and older), prioritize nutrient-dense foods, control portion sizes, and stay active for overall well-being." << endl;
    }
}
void ShowDietPlan(float bmi , int age ){
     cout << "Based on BMI and age, here are some general diet recommendations:" << endl;

    if (bmi < 18.5) {
        cout << "You are underweight. Consider focusing on nutrient-dense foods to achieve a healthy weight." << endl;
    } else if (bmi >= 18.5 && bmi < 25) {
        cout << "You have a normal weight. Maintain a balanced diet with a variety of nutrient-rich foods." << endl;
    } else if (bmi >= 25 && bmi < 30) {
        cout << "You are overweight. Consider focusing on a balanced diet with a slight calorie deficit for weight loss." << endl;
    } else {
        cout << "You are obese. Aim for gradual, sustainable weight loss through a balanced diet and regular physical activity." << endl;
    }
    ShowDietPlanAge(age) ; 
}


void printList(const WeightLinkedList &weightList)
{
    Node *currentNode = weightList.head;
    cout << "Weight Linked List: ";
    while (currentNode)
    {
        cout << currentNode->data << " -> ";
        currentNode = currentNode->next;
    }
    cout << "nullptr" << endl;
}
void keepTrackofWeight(string userid)
{
    WeightLinkedList weightList;

    takeAndStoreWeight(weightList);
    takeAndStoreWeight(weightList);
    takeAndStoreWeight(weightList);
    printList(weightList);
    bmiForEachWeight(weightList , userid);
}
float retrievheightfromfile(string userId){
    float height  ; 
    ifstream file(userId +".txt") ; 
    string line ; 
    getline(file, line); // Name skip
    getline(file, line); // Age skip
    getline(file, line); // Gender skip
    getline(file, line); // User ID (skip)
    getline(file, line); // Height
    string heightString = line;
    height = stof(heightString);
    getline(file, line); // Weight(skip)
    
    getline(file, line); // Password (skip)   
    file.close();
    return height ;
    }
float retrievWeightFromFile(string userId){
    float weight  ; 
    ifstream file(userId +".txt") ; 
    string line ; 
    getline(file, line); // Name skip
    getline(file, line); // Age skip
    getline(file, line); // Gender skip
    getline(file, line); // User ID (skip)
    getline(file, line); // Height(skip)
    getline(file, line); // Weight(skip)
    string weightString = line;
    weight = stof(weightString);
    getline(file, line); // Password (skip)   
    file.close();
    return weight ;
    }
string loginUser()
{
    string userId, password;
    cout << "Enter your ID: ";
    cin >> userId;
    if (!checkUserExists(userId))
    {
        cout << "User with ID " << userId << " does not exist." << endl;
    }
    cout << "Enter your password: ";
    cin >> password;
    // Read user data from the corresponding text file
    ifstream file(userId + ".txt");
    string line;
    getline(file, line); // Name
    string name = line;
    getline(file, line); // Age
    string ageString = line;
    int age = stoi(ageString);
    getline(file, line); // Gender
    string gender = line;
    getline(file, line); // User ID (skip)
    getline(file, line); // Height
    string heightString = line;
    float height = stof(heightString);
    getline(file, line); // Weight
    string weightString = line;
    float weight = stof(weightString);
    getline(file, line); // Password (check)
    if (password != line)
    {
        cout << "Incorrect password. Please try again." << endl;
        file.close();
        return "wrongpassword" ; 
    }
    file.close();
    int q;
    float w = calculateBMI2(weight, userId);
    while(1){
    cout << "0. If you want to compare your previous 3 bmi then enter last 3 weight that you have trace " << endl;
    cout<<"1. If you want to see workout plan  "<<endl ; 
    cout<<"2. If you want to see diet paln acording to your bmi and age"<<endl ; 
    cout<<"3. if you want to compare your weight with your friends  "<< endl ;
    cout<<"4. if you want to compare your height with your friends  "<< endl ;
    cout<<"5. if you want to redirect to main page "<<endl  ; 
    cin >> q;
    switch (q)
    {
    case 0:
        keepTrackofWeight(userId);
        break;
    case 1:
        ShowWorkoutPlan(w) ; 
        break;
    case 2 :
        ShowDietPlan(w , age) ; 
        break;
    case 3:
        cout<<"friend fxn call"<<endl ;
        friendsData();
        break;
    case 4:
        cout<<"friend fxn call for height"<<endl ; 
        friendsDataHeight() ;
        break;
    case 5:
        cout<<"program redirected to main page"<<endl ;
        return "program redirected";

    }        
    }
    return userId;
    // Calculate BMI
}


int main()
{
    bool exit = false;
    int choice;

    while (!exit)
    {
        cout << "Choose an option:" << endl;
        cout << "1. Register a new user" << endl;
        cout << "2. Log in as an existing user" << endl;
        // cout << "3. If you want to compare your previous 3 bmi then enter last 3 weight that you have trace "<<endl  ;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registerUser();
            break;

        case 2:
            loginUser();
            break;

        case 0:
            exit = true;
            break;
        // case 3:
        //     keepTrackofWeight() ;
        // break ;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
    cout << "Exiting the program. Goodbye!" << endl;
    return 0;
}