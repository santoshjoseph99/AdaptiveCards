//
//  ACRColumnView
//  ACRColumnView.mm
//
//  Copyright © 2017 Microsoft. All rights reserved.
//

#import "ACRColumnView.h"

@implementation ACRColumnView

- (void)config:(nullable NSDictionary<NSString *, id> *)attributes
{
    self.stackView.axis = UILayoutConstraintAxisVertical;
    [super config:attributes];
    self.isLastColumn = NO;
}

- (void)addArrangedSubview:(UIView *)view
{
    // if auto, maintain content size whenever possible
    if ([self.columnWidth isEqualToString:@"auto"]) {

        NSInteger priority = ACRColumnWidthPriorityAuto;
        if (self.isLastColumn) {
            priority = ACRColumnWidthPriorityStretchAuto;
        }

        [view setContentHuggingPriority:priority forAxis:UILayoutConstraintAxisHorizontal];
        [view setContentCompressionResistancePriority:UILayoutPriorityDefaultHigh forAxis:UILayoutConstraintAxisHorizontal];
        // if columnWidth is set to stretch or number, allow column to fill the available space
    } else if ([self.columnWidth isEqualToString:@"stretch"]) {
        [view setContentHuggingPriority:ACRColumnWidthPriorityStretch forAxis:UILayoutConstraintAxisHorizontal];
        [view setContentCompressionResistancePriority:UILayoutPriorityDefaultLow forAxis:UILayoutConstraintAxisHorizontal];
    } else {
        [view setContentHuggingPriority:UILayoutPriorityDefaultLow forAxis:UILayoutConstraintAxisHorizontal];
        [view setContentCompressionResistancePriority:UILayoutPriorityRequired forAxis:UILayoutConstraintAxisHorizontal];
    }

    [self.stackView addArrangedSubview:view];
}

- (UIView *)addPaddingSpace
{
    UIView *blankTrailingSpace = [[UIView alloc] init];
    [blankTrailingSpace setContentHuggingPriority:UILayoutPriorityDefaultLow forAxis:UILayoutConstraintAxisVertical];
    [self addArrangedSubview:blankTrailingSpace];
    return blankTrailingSpace;
}

@end
