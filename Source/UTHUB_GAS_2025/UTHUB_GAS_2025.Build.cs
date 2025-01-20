// Copyright Epic Games, Inc. All Rights Reserved.

using System.Reflection;
using UnrealBuildTool;

public class UTHUB_GAS_2025 : ModuleRules
{
	public UTHUB_GAS_2025(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
	        "Core", "CoreUObject", "Engine", "InputCore", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput"
        });
        
        PrivateDependencyModuleNames.AddRange(new string[]
        {
	        "GameplayAbilities", "GameplayTasks", "GameplayTags"
        });
        
        PublicIncludePaths.Add(ModuleDirectory + "/Public");
    }
}
