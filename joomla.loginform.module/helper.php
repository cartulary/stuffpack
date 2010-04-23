<?php
	class modCrossLoginHelper
	{
		function getForm($params)
		{
			return <<<END
<form action="{$params->get('formaction','')}" method="post" id="cross-login">
<label for="username">Username</label>
<input type="text" name="username" id="username" size="15" value="admin" />
<label for="password">Password</label>
<input type="password" name="password" id="password" size="15" value="" />
<input type="submit" value="Login" />
<input type="hidden" name="testcookies" value="1" />
</form>
END;
		}
	}
?>