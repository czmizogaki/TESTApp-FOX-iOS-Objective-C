//
//  ViewController.m
//  TestAppFox4.0.0
//
//  Created by MMizogaki on 8/19/16.
//  Copyright © 2016 MMizogaki. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];


    FOXEvent* event = [[FOXEvent alloc] initWithEventName:@"tuturial" andLtvId:0000];
    event.buid = @"User ID";
    [FOXTrack sendEvent:event];
}

- (void)viewWillAppear:(BOOL)animated {

    [super viewWillAppear:animated];

    FOXEvent* event = [[FOXEvent alloc] initWithEventName:@"purchase"];
    event.price = 99;
    event.currency = @"JPY";
    event.sku = @"itemId";
    [FOXTrack sendEvent:event];
}

- (void)viewDidAppear:(BOOL)animated {

    [super viewDidAppear:animated];

    // 初回起動のインストール計測
    FOXTrackOption* option = [FOXTrackOption new];
    option.optout = YES;
    [FOXTrack onLaunchWithOption:option];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
