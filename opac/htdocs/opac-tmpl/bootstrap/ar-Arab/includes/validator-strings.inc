<!-- validator-strings.inc -->
<script>
    $(document).ready(function(){
        jQuery.extend(jQuery.validator.messages, {
            required: _("هذا الحقل مطلوب."),
            remote: _("يرجى إصلاح هذا الحقل."),
            email: _("يرجى إدخال عنوان بريد إلكتروني صحيح."),
            url: _("يرجى إدخال عنوان URL صحيح."),
            date: _("يرجي إدخال تاريخ صحيح."),
            dateISO: _("يرجى إدخال تاريخ صحيح (آيزو)"),
            number: _("يرجى إدخال رقم صحيح."),
            digits: _("يرجى إدخال أرقام فقط."),
            equalTo: _("يرجى إدخال نفس القيمة مرة أخرى."),
            maxlength: $.validator.format(_("يرجى عدم إدخال أكثر من {0} حرفا.")),
            minlength: $.validator.format(_("يرجى إدخال {0} حرفا على الأقل.")),
            rangelength: $.validator.format(_("يرجى إدخال قيمة بين {0} و {1} في طول الأحرف.")),
            range: $.validator.format(_("يرجى إدخال قيمة ما بين {0} و {1}.")),
            max: $.validator.format(_("يرجى إدخال قيمة أقل من أو تساوي {0}.")),
            min: $.validator.format(_("يرجى إدخال قيمة أكبر من أو تساوي {0}.")),
            phone: $.validator.format(_("يرجى إدخال رقم هاتف صحيح."))
        });
    });
</script>
<!-- / validator-strings.inc -->
