   M S B A M L   `   `   `  ����E  ATaskify0.5, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullE'clr-namespace:Taskify0._5.CustomControlTaskify0._5.CustomControl  5   	   )clr-namespace:Taskify0._5Taskify0._5  5   	       Taskify0._5.MainWindow   5   	   W SPresentationCore, Version=7.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=7.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35e aSystem.Windows.Controls.Ribbon, Version=7.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089R NWindowsBase, Version=7.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     5   	   R NSystem.Xaml, Version=7.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   Z VFontAwesome.WPF, Version=4.7.0.37774, Culture=neutral, PublicKeyToken=0758b07a11a4f466.fa1$http://schemas.fontawesome.io/icons/  5   	   4custom'clr-namespace:Taskify0._5.CustomControl  5   	   %localclr-namespace:Taskify0._5  5   	     � Title$  
MainWindow��5   	   $	��450��6   $	��800��6)   $	��500��65    � 	Resources 5         MyTextBoxStyle �� 
TargetType �� Property �� Value  	TextColor��%7  &	        �� 5	   
   " ��6'   .�5
      ��  � �� �#2828286+   �� 5       � ��$ 16(�6)   �� 5       � ��$ Center=�69   �� 5       � ��# �  6+   �� 5       � ��$ 0q�60   �� 5       � ��$ 45��6'   �� 5       � ��$ 25 0 0 0q�6(   5      5      .��5      �  
 Window#��[ 6    � RowDefinitions 5   
   �� 5      .+�5   
   .   (Taskify0._5.CustomControl.CustomControl1  6"   � 5   
   $��1��6    � ColumnDefinitions 5       �� 5!      $
��Auto �6#   $��0��60   $	��250��6=   �� 5"      $��3 �6#   �� 5#      $��* �6#   .+�5'      � -   5         �Name$ 	NavDrawer��5'        	NavDrawer#���  6&   $��325px��6J   $��0��6X   .+�5(      �� .+�5)      ��  �� Orientation$ 
Horizontal=�6!   .+�5*      A� $��50��6"   $��50��6-   $��
20 25 0 20q�69   $
��Left=�6M   ��5+      �� 5,   "   	 �� ImageSource$	 	image.jpg��6-   5.      �� 5/      $��15 5 0 0q�6%   $��Center=�67   .+�50      �� #���  6$   .��6M   
Chamster52      �� 53        MailText#���  6$   .��6L   mikitakoukel@mail.ru56        57      58      59      �� 5;      $
��True��6#   $	��600��6;   $	��285��6H   .��5=      �� $	��315��6%   $
��0 10q�61   $	��600��6?   .+�5>      �� -   5        
 ��Name$	
 All��5>   %   #���  62     NoAccentColor#���  6[   $��Все��6�   $	��220��6�   $
��Left=�6�   $��10 0 0 4q�6�   6�   �� 5?      -   5        $
 Input��5?   %   #���  64   $��Входящие��6]   $	��220��6p   $
��Left=�6|   $��10 0 0 4q�6�   #���  6�   �� 5@      -   5        $

 Home��5@   ]   #���  6%   $
��Home��6N   $	��220��6k   $
��Left=�6w   $��10 0 0 4q�6�   #���  6�   R� 5A      .@�5B   "   R� $
��Left=�6+   .@�5C   &   Q� $��Parent 1��63   .@�5D   *   Q� $��Child 1��67   Q� 5E   *   $��Child 2��67   5F   '   5G   #   R� 5H   "   .@�5I   *   Q� $��Parent 2��67   .@�5J   *   Q� $��Child 3��67   Q� 5K   *   $��Child 4��67   5L   '   5M   #   5N      5O      5P      5Q      �� 5S      $��Bottom=�6   $ 
Horizontal=�68   .+�5T      d� -   5         d�Name$ ToggleButton��5T   �   $��
10 10 0 10q�6$     ToggleButton#��[ 68   $��Bottom=�6^   $
��Left=�6y   
������ $��0q�6�   $C��=pack://application:,,,/FontAwesome.WPF;component/#FontAwesome)�6�   5U      d� 5W      -   5        $ ThemeChanger��5W   ]   $��	0 10 0 10q�6$     ThemeChanger#��[ 67   $��Bottom=�6s   $
��Left=�6�   
������ $��0q�6�   $C��=pack://application:,,,/FontAwesome.WPF;component/#FontAwesome)�6�   5X      �� 5Y      -   5        $��	0 10 0 10q�5Y        Undo#��[ 60   $��Bottom=�6N   $��Right=�6i   
������ $��0q�6�   $C��=pack://application:,,,/FontAwesome.WPF;component/#FontAwesome)�6�   5Z      �� 5[      -   5        $��	0 10 0 10q�5[       	 Redo#��[	 60   $��Bottom=�6N   $��Right=�6i   
������ $��0q�6�   $C��=pack://application:,,,/FontAwesome.WPF;component/#FontAwesome)�6�   5\      5]      5^      �� 5_      -	   5        $��1��5_      #���  6+    �� ShowsPreview$ False��6X   $��30��6m   $��Center=�6x    J� RenderTransformOrigin$ -7.383,0.485&�6�   � 5a      -
   5        $
 Main��5a   #   $��2��6    
 Main#��� 
 61   .+�5b      � $��Stretch=�6   $��Stretch=�65   $��45 35 35 45q�6Q   .+�5c      �� .+�5d      �� -   5         ��Name$ Header��5d   \   #���  6$   $��35(�6N   $
��Left=�6l   Входящие6�   �� 5e      $
��True��6'   $��Visible=�6?   $��10q�6e   $	��265��6q   .��5f      �� -   5         ��Name$ 	toDosXaml��5f   3   $	��550��6&   $��	0 25 0 25q�6F     AccentColor#���  6Y     ListBoxItemStyle#��[ 6�     ToDoTemplate#��[ 6�   ��6�   �� *toDos+6�   5g      5h      �� 5i      -   5         ��Name$ inputTextBox��5i      $��Bottom=�64   $
��Auto��6P   $	��150��6]   6�   5j      5k      5l      5m      5n      