<div id="overdrive-login" class="modal" tabindex="-1" role="dialog" aria-labelledby="overdrive-login-label" aria-hidden="true">
 <div class="modal-dialog">
 <div class="modal-content">
 <div class="modal-header">
 <h3 id="overdrive-login-label" class="modal-title">تسجيل دخول</h3>
 <button aria-label="إغلاق" class="closebtn" data-dismiss="modal" type="button">
 <span aria-hidden="true">&times;</span>
 </button>
 </div>
 <form action="#" id="overdrive-login-form">
 [% INCLUDE 'csrf-token.inc' %]
 <div class="modal-body">
 <fieldset class="brief">
 <label for="ODpassword">كلمة المرور:</label>
 <input type="password" name="ODpassword" id="ODpassword" value="" autocomplete="off" />
 </fieldset>
 </div>
 <div class="modal-footer">
 <input class="btn btn-primary overdrive-checkout-submit" type="submit" value="تسجيل دخول" />
 <a href="#" data-dismiss="modal" aria-hidden="true" class="cancel">إلغاء</a>
 </div>
 </form> <!-- /#overdrive-login-form -->
 </div> <!-- /.modal-content -->
 </div> <!-- /.modal-dialog -->
</div> <!-- /#overdrive-login -->
