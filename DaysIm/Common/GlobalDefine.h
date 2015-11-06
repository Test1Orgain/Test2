//
//  GlobalDefine.h
//  MemoryPuzzle
//
//  Created by slyao on 14/12/29.
//  Copyright (c) 2014年 slyao. All rights reserved.
//

#ifndef MemoryPuzzle_GlobalDefine_h
#define MemoryPuzzle_GlobalDefine_h

#define SELECT_STYLE_NOTICE @"selectstylenotice"

// 颜色值
#define RGBCOLOR(r,g,b)             [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1]
#define RGBACOLOR(r,g,b,a)          [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]

//屏幕尺寸
#define SCREEN_WIDTH                [UIScreen mainScreen].bounds.size.width
#define SCREEN_HEIGHT               [UIScreen mainScreen].bounds.size.height

#define IOS7_OR_LATER     ( [[[UIDevice currentDevice] systemVersion] compare:@"7.0"] != NSOrderedAscending )

typedef enum
{
    MemoryPuzzleStyleScenery = 0,       //风景
    MemoryPuzzleStyleCar,           //汽车
    MemoryPuzzleStyleBeauty,        //美女
    MemoryPuzzleStyleComic,         //动漫
}MemoryPuzzleStyle;

#endif
