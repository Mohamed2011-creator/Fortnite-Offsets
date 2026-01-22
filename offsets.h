pragma once
#include <cstdint>

namespace globals
{
    uint64_t UWorld          = 0x178C37A8;
    uint64_t GNames          = 0x1777E080;
    uint64_t GEngine         = 0x178C50A8;
    uint64_t GObjects        = 0x1785AFB0;
    uint64_t GObjectsCount   = 0x1785AFB8;
 
    uint64_t StaticFindObject = 0x73AC13;
    uint64_t StaticLoadObject = 0x960153;
    uint64_t ProcessEvent     = 0x86FAA;
 
    uint64_t DrawTransition  = 0x513D88;
    uint64_t BoneMatrix      = 0x55B004;
}

namespace offsets
{
    uint64_t RootComponent        = 0x1B0;
    uint64_t PlayerState          = 0x2D0;
    uint64_t Mesh                 = 0x330;
 
    uint64_t GameState            = 0x1D0;
    uint64_t OwningGameInstance   = 0x248;
    uint64_t LocalPlayers         = 0x38;
    uint64_t PlayerArray          = 0x2C8;
 
    uint64_t PlayerController     = 0x30;
    uint64_t AcknowledgedPawn     = 0x358;
    uint64_t NetConnection        = 0x528;
 
    uint64_t TargetedFortPawn     = 0x1830;
    uint64_t LocationUnderReticle = 0x2A50;
 
    uint64_t bIsABot              = 0x2BA;
    uint64_t PawnPrivate          = 0x328;
    uint64_t Platform             = 0x440;
 
    uint64_t TeamIndex            = 0x11B1;
    uint64_t KillScore            = 0x11C8;
 
    uint64_t RankedProgress       = 0xD8;
 
    uint64_t bIsDying              = 0x728;
    uint64_t bIsDBNO               = 0x841;
    uint64_t CurrentWeapon         = 0x990;
 
    uint64_t bIsReloadingWeapon    = 0x3D1;
    uint64_t WeaponData            = 0x600;
    uint64_t AmmoCount             = 0x147C;
 
    uint64_t ItemType              = 0xA8;
    uint64_t PrimaryAssetOverride  = 0xA9;
    uint64_t Rarity                = 0xAA;
}

// Offsets from https://github.com/urfavhazee/Fortnite-Offsets/
