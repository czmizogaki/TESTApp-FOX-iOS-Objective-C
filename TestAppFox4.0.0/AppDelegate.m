//
//  AppDelegate.m
//  TestAppFox4.0.0
//
//  Created by MMizogaki on 8/19/16.
//  Copyright © 2016 MMizogaki. All rights reserved.
//

#import "AppDelegate.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    [[FOXConfig configWithAppId:74237413297489211
                           salt:@""
                         appKey:@""]activate];

    FOXTrackOption* option = [FOXTrackOption new];
    option.redirectURL = @"myapp://top"; // URLスキーム
    option.buid = @"USER ID"; // 任意ID
    option.optout = YES;
    option.onTrackFinished = ^ {
        NSLog(@"callback after tracking finished");
    };
    [FOXTrack onLaunchWithOption:option];


    if ([application applicationState] == UIApplicationStateBackground){
        //バックグラウンド時の処理
    } else {
        //バックグラウンド時は起動計測が呼ばれないようにする
        [FOXTrack startSession];
    }


    return YES;
}

-(BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {

    [FOXTrack handleOpenURL:url];

    return YES;
}

-(BOOL) application:(UIApplication *) application continueUserActivity:(NSUserActivity *) userActivity
 restorationHandler:(void (^)(NSArray *restorableObjects)) restorationHandler {

    [FOXTrack handleOpenURL:userActivity.webpageURL];
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {

}

- (void)applicationDidEnterBackground:(UIApplication *)application {

    [FOXTrack startSession];
}

- (void)applicationWillEnterForeground:(UIApplication *)application {

}

- (void)applicationDidBecomeActive:(UIApplication *)application {

}

- (void)applicationWillTerminate:(UIApplication *)application {

}

@end
