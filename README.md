# Codename: Amazaballz

## Tools
In order to work on this project, you **MUST** install these tools.

1. Unreal 4 4.15 to develop the game in - available [here](https://www.unrealengine.com/download?dismiss=null)
2. Visual Studio 2015 Community Edition to develop C++ code and compile for the project - available [here](https://www.visualstudio.com/downloads/)
3. SourceTree used for providing a UI interface for Git - available [here](https://www.sourcetreeapp.com/)
4. GitHub for Source Control - you're already here!
5. Slack for keeping up to date with all of the team tasks and chat - link available for existing and new members on request.
6. Trello for helping with task organisation - link available for existing and new members on request.

## Project Guidelines 
Please follow the naming conventions as closely as possible:

1. Blueprints - BP_BlueprintName.
2. Maps - MP_MapName.
3. Materials - MAT_MaterialName.
4. Meshes - MSH_MeshName.
5. Physics Materials - PMAT_PhysicsMaterialName.
6. C++ Classes - C_ClassName.

## Programming Guidelines

1. C++ Standard
    * Member Variables: 
        * Start with a lower case letter. e.g. `variable_a_`. But `variable_a` or `variableA` is incorrect.
	* Temporary Variables:
		* Variables that are used just within scope of a function for example, start with a lower case letter and DO NOT end with an underscore, e.g. 'variable_a'
    * Enums:
		* Start with an E_ prefix then the name of what that enum represents, e.g. E_AffectedPlayers.

2. Getters and setters are up to the programmer. If the variable is needed for blueprints, please use the UFUNCTION property to provide access to the variable from blueprints:
	* E.g. UFUNCTION(BlueprintCallable, Category = "Category Name")
	* Set the category name to something that is associated with this class object.

3. To provide access to C++ variables in Unreal 4 please use the UPROPERTY field:
	* UPROPERTY(EditAnywhere, Category = "Category Name in Details Pane")
	
4. Comment at the top of a file if you've worked in it using the block comment headers:

    ```
	/*
	 * Class Name
	 * ==========
	 * 
	 * Created: date time
	 * Class Name: Name of the class.
	 * Base Class: (If applicable) Name of the base class.
	 * Author(s): Name of the people whom have worked on this file.
	 *
	 * Purpose: The purpose of this file.
	 */
    ```
	
5. Use block commenting (/* */) for summaries on objects. Follow this specific commenting convention for methods:

	```
	/*
	 * Function summary here
	 * @param param-name param-summary
	 * @return the value it returns
	 */
	```
	
	* This can be used to generate documentation.

6. Use C++ style casts and features. For instance, dynamic_cast<>/static_cast<>.