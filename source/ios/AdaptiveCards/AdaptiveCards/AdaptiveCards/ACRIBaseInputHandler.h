//
//  ACRIBaseInputHandler
//  ACRIBaseInputHandler.h
//
//  Copyright © 2017 Microsoft. All rights reserved.
//

#import "ACRErrors.h"
#import <Foundation/Foundation.h>

@protocol ACRIBaseInputHandler

- (BOOL)validate:(NSError **)error;

- (void)getInput:(NSMutableDictionary *)dictionary;

@end
