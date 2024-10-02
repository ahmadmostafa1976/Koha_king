[% USE raw %]
<!-- str/cataloging_additem.inc -->
<script>
    var searchid = '[% searchid | html %]';
    var biblionumber = '[% biblionumber | html %]';
    var frameworkcode = '[% frameworkcode | html %]';
    [% IF popup %]
      var popup = true;
    [% ELSE %]
      var popup = false;
    [% END %]
    var op = '[% op | html %]';
    var LABEL_EDIT_ITEM = _("تحرير المادة");
    var LABEL_DELETE_ITEM = _("حذف المادة");
    var MSG_FORM_NOT_SUBMITTED = _("الشكل غير مقدم بسبب المشاكل التالية");
    var MSG_MANDATORY_FIELDS_EMPTY = _("%s الحقول الإلزامية فارغة (مظلل)");
    var MSG_IMPORTANT_FIELDS_EMPTY = _("%s حقول هامة فارغة (مظللة)");
    var MSG_ADD_MULTIPLE_ITEMS = _("أنت على وشك إضافة %sمادة. متابعة؟");
    var MSG_ENTER_NUM_ITEMS = _("يرجى إدخال عدد المواد لإنشائها.");
    var MSG_CONFIRM_DELETE_ITEM = _("هل أنت متأكد من أنك تريد حذف هذه المادة؟");
    var MSG_CONFIRM_ADD_ITEM = _("هل أنت متأكد من أنك تريد إضافة مادة جديدة؟ ستفقد أي تغييرات أجريت في هذه الصفحة.");
    var MSG_CONFIRM_SAVE = _("هل أنت متأكد من أنك تريد الحفظ؟");
    var table_settings = [% TablesSettings.GetTableSettings( 'cataloguing', 'additem', 'itemst', 'json' ) | $raw %];
</script>
<!-- / str/cataloging_additem.inc -->
