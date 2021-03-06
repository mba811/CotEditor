/*
 ==============================================================================
 CEEditorWrapper
 
 CotEditor
 http://coteditor.com
 
 Created on 2004-12-08 by nakamuxu
 encoding="UTF-8"
 
 ------------
 This class is based on JSDTextView (written by James S. Derry – http://www.balthisar.com)
 JSDTextView is released as public domain.
 arranged by nakamuxu, Dec 2004.
 ------------------------------------------------------------------------------
 
 © 2004-2007 nakamuxu
 © 2014-2015 1024jp
 
 This program is free software; you can redistribute it and/or modify it under
 the terms of the GNU General Public License as published by the Free Software
 Foundation; either version 2 of the License, or (at your option) any later
 version.
 
 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License along with
 this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 Place - Suite 330, Boston, MA  02111-1307, USA.
 
 ==============================================================================
 */

@import Cocoa;
#import "CETextView.h"


@class CETextView;
@class CETheme;


@interface CEEditorWrapper : NSResponder

@property (nonatomic) BOOL showsLineNum;
@property (nonatomic) BOOL wrapsLines;
@property (nonatomic) BOOL showsPageGuide;
@property (nonatomic) BOOL showsInvisibles;
@property (nonatomic, getter=isVerticalLayoutOrientation) BOOL verticalLayoutOrientation;
@property (nonatomic) CETextView *focusedTextView;

@property (readonly, nonatomic) BOOL showsNavigationBar;
@property (readonly, nonatomic) BOOL canActivateShowInvisibles;


#pragma mark Public Methods

// text processing
- (NSString *)string;
- (NSString *)substringWithRange:(NSRange)range;
- (NSString *)substringWithSelection;
- (NSString *)substringWithSelectionForSave;  // line ending applied
- (void)setString:(NSString *)string;

- (void)insertTextViewString:(NSString *)inString;
- (void)insertTextViewStringAfterSelection:(NSString *)string;
- (void)replaceTextViewAllStringWithString:(NSString *)string;
- (void)appendTextViewString:(NSString *)string;

- (NSRange)selectedRange;  // line ending applied
- (void)setSelectedRange:(NSRange)charRange;  // line ending applied

- (void)markupRanges:(NSArray *)ranges;
- (void)clearAllMarkup;

- (BOOL)isAutoTabExpandEnabled;

// navigation bar
- (void)setShowsNavigationBar:(BOOL)showsNavigationBar animate:(BOOL)performAnimation;

// font
- (NSFont *)font;
- (void)setFont:(NSFont *)font;
- (BOOL)usesAntialias;

// theme
- (void)setThemeWithName:(NSString *)themeName;
- (CETheme *)theme;

// syntax
- (NSString *)syntaxStyleName;
- (void)setSyntaxStyleName:(NSString *)inName recolorNow:(BOOL)recolorNow;
- (void)recolorAllString;
- (void)updateColoringAndOutlineMenuWithDelay;
- (void)setupColoringTimer;


#pragma mark Action Messages

- (IBAction)toggleLineNumber:(id)sender;
- (IBAction)toggleNavigationBar:(id)sender;
- (IBAction)toggleLineWrap:(id)sender;
- (IBAction)toggleLayoutOrientation:(id)sender;
- (IBAction)toggleAntialias:(id)sender;
- (IBAction)toggleInvisibleChars:(id)sender;
- (IBAction)togglePageGuide:(id)sender;
- (IBAction)toggleAutoTabExpand:(id)sender;
- (IBAction)selectPrevItemOfOutlineMenu:(id)sender;
- (IBAction)selectNextItemOfOutlineMenu:(id)sender;
- (IBAction)openSplitTextView:(id)sender;
- (IBAction)closeSplitTextView:(id)sender;
- (IBAction)recolorAll:(id)sender;

@end




#pragma mark -

typedef NS_ENUM(NSUInteger, CEGoToType) {
    CEGoToLine,
    CEGoToCharacter
};

@interface CEEditorWrapper (Locating)

- (NSRange)rangeWithLocation:(NSInteger)location length:(NSInteger)length;
- (void)setSelectedCharacterRangeWithLocation:(NSInteger)location length:(NSInteger)length;
- (void)setSelectedLineRangeWithLocation:(NSInteger)location length:(NSInteger)length;
- (void)gotoLocation:(NSInteger)location length:(NSInteger)length type:(CEGoToType)type;

@end
