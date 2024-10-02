[%- BLOCK keyboard_shortcut_descriptions -%]
 [% SWITCH shortcut_name %]
 [%- CASE 'insert_copyright' -%]<span>قم بإدخال رمز حقوق النشر (©)</span>
 [%- CASE 'insert_copyright_sound' -%]<span>قم بإدخالرمز حقوق النشر (℗) (التسجيلات الصوتية)</span>
 [%- CASE 'insert_delimiter' -%]<span>قم بإدخال محدد  (‡)</span>
 [%- CASE 'subfield_help' -%]<span>الحصول على مساعدة حول الحقل الفرعي الحالي</span>
 [%- CASE 'link_authorities' -%]<span>ربط الحقل إلى الاستنادات</span>
 [%- CASE 'delete_field' -%]<span>حذف الحقل الحالي ونسخ إلى 'الحافظة'</span>
 [%- CASE 'delete_subfield' -%]<span>حذف الحقل الفرعي الحالي ونسخ إلى 'الحافظة'</span>
 [%- CASE 'new_line' -%]<span>حقل جديد في السطر التالي</span>
 [%- CASE 'line_break' -%]<span>قم بإدخال فاصل سطر</span>
 [%- CASE 'next_position' -%]<span>انتقل للموضع التالي</span>
 [%- CASE 'prev_position' -%]<span>انتقل للموضع السابق</span>
 [%- CASE 'toggle_keyboard' -%]<span>تبديل لوحة المفاتيح</span>
 [%- CASE 'copy_line' -%]<span>نسخ الحقل الحالي</span>
 [%- CASE 'copy_subfield' -%]<span>نسخ الحقل الفرعي الحالي</span>
 [%- CASE 'paste_line' -%]<span>لصق التحديد من 'الحافظة'</span>
 [%- CASE 'insert_line' -%]<span>نسخ الحقل الحالي في السطر التالي</span>
 [%- END -%]
[%- END -%]
