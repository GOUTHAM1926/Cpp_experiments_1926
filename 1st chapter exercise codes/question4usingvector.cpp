#include<iostream>
//#include<vector>
//#include<string>
using namespace std;
//Function to display glossary 
/*void displayGlossary()
{
    cout<< "\n===COOKING GLOSSARY==="<<endl;
    cout << "Oven: A kitchen appliance that uses heat to cook food" << endl;
    cout << "Preheat: To heat the oven to desired temperature before cooking" << endl;
    cout << "Muffin pan: A baking tray with 12 cup-shaped indentations" << endl;
    cout << "Whisk: To mix ingredients rapidly with a fork or whisk tool" << endl;
    cout << "Fold: To gently combine ingredients without overmixing" << endl;
    cout << "Batter: The mixed wet and dry ingredients before baking" << endl;
    cout << "Toothpick test: Insert toothpick in center - if it comes out clean, it's done" << endl;
    cout << "========================" << endl << endl;
}
//Function to display ingredients
void displayIngredients(){
    cout<<"===INGREDIENTS NEEDED==="<<endl;
    cout << "- 2 cups all-purpose flour" << endl;
    cout << "- 3/4 cup granulated sugar" << endl;
    cout << "- 2 teaspoons baking powder" << endl;
    cout << "- 1/2 teaspoon salt" << endl;
    cout << "- 1/3 cup vegetable oil" << endl;
    cout << "- 1 large egg" << endl;
    cout << "- 1 cup milk" << endl;
    cout << "- 1 cup fresh blueberries" << endl;
    cout << "=========================" << endl << endl;
}
//FUNCTION TO DISPLAY KITCHEN TOOLS 
void displayKitchenTools(){
      cout << "=== KITCHEN TOOLS NEEDED ===" << endl;
    cout << "- 1 muffin pan (12-cup capacity)" << endl;
    cout << "- 2 mixing bowls (1 large, 1 medium)" << endl;
    cout << "- 1 whisk or fork" << endl;
    cout << "- 1 measuring cup set" << endl;
    cout << "- 1 set measuring spoons" << endl;
    cout << "- 1 wooden spoon or spatula" << endl;
    cout << "- Muffin liners or cooking spray" << endl;
    cout << "- 1 toothpick" << endl;
    cout << "- Oven mitts" << endl;
    cout << "============================" << endl << endl;
}
//Main recipe function with detailed steps
void displayRecipeSteps(){
    vector<string> steps ={
          "Put on an apron to protect your clothes. Wash your hands thoroughly with soap.",
        
        "Turn on your oven by pressing the power button. Set temperature to 375°F (190°C). Wait for oven to preheat (usually takes 10-15 minutes). A light will turn off when ready.",
        
        "Get your muffin pan. Either spray each cup with cooking spray OR place one paper muffin liner in each of the 12 cups.",
        
        "Get a large mixing bowl. Add 2 cups flour, 3/4 cup sugar, 2 teaspoons baking powder, and 1/2 teaspoon salt. Use a whisk to mix these dry ingredients together until combined.",
        
        "Get a medium mixing bowl. Crack 1 egg into it (throw away shell). Add 1 cup milk and 1/3 cup oil. Whisk these wet ingredients together until the egg is completely mixed in.",
        
        "Pour the wet ingredients from the medium bowl into the large bowl with dry ingredients. Use a wooden spoon to gently stir until JUST combined. Do NOT overmix - some lumps are okay.",
        
        "Gently add 1 cup blueberries to the batter. Use the wooden spoon to fold them in with just a few gentle stirs.",
        
        "Using a large spoon, divide the batter evenly among the 12 muffin cups. Fill each cup about 2/3 full.",
        
        "Put on oven mitts. Carefully place the muffin pan on the center rack of the preheated oven. Close the oven door.",
        
        "Set a timer for 20 minutes. Do not open the oven door during baking.",
          "When timer goes off, put on oven mitts. Insert a toothpick into the center of one muffin. If it comes out clean or with just a few moist crumbs, muffins are done. If batter sticks to toothpick, bake 2-3 more minutes.",
        
        "Put on oven mitts. Carefully remove muffin pan from oven using both hands. Place on a heat-safe surface like a cooling rack or trivet.",
        
        "Let muffins cool in pan for 5 minutes. Then carefully turn pan upside down to remove muffins, or lift each muffin out individually.",
        
        "Let muffins cool for another 10 minutes before eating. Enjoy your homemade blueberry muffins!"
    };

    cout<<"===Detailed step-by-step instructions==="<<endl;
    for (int i=0;i<steps.size();i++){
        cout<< "Step" << (i+1) << ":" << steps[i] << endl <<endl ;
    }
} */
void displayGlossary();
void displayIngredients();
void displayKitchenTools();
void displayRecipeSteps();
int main(){
      cout << "BLUEBERRY MUFFIN RECIPE PROGRAM" << endl;
    cout << "================================" << endl << endl;
     cout << "This program demonstrates detailed, step-by-step instructions" << endl;
    cout << "similar to how we must be explicit in programming!" << endl << endl;
    //Display all sections
    displayGlossary();
    displayIngredients();
    displayKitchenTools();
    displayRecipeSteps();
    
    cout << "=== PROGRAMMING LESSON ===" << endl;
    cout << "Just like this recipe needed every detail spelled out for a beginner," << endl;
    cout << "programming requires us to be explicit about every step." << endl;
    cout << "Computers can't assume or fill in missing information!" << endl;
    cout << "=========================" << endl;
    
    return 0;
}
/* Here ,we're running this by calling different void functions from different files ,
so we need to compile all at once so the linker can link all the object files together to make the executable file.
use this command to run in terminal :g++ question4usingvector.cpp displayrecipesteps.cpp displaykitchentools.cpp displayingredients.cpp displayglossary.cpp */