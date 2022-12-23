// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GAS_Learn : ModuleRules
{
    public GAS_Learn(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "GameplayAbilities", "GameplayTags", "GameplayTasks", "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
    }
}
