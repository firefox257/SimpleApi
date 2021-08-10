import {$} from "/tie.js";
import {} from "/ui/ui.js";

const html = `
<comp tietype="button" color ="danger" tieinner tieobj="obj"></comp>
`;

function try1buttonfunc()
{
	var at =
	{
		obj: undefined,
		init()
		{
			at.obj.onclick = at.attributes.onclick;
		}
	};
	return at;
};
try1buttonfunc.html = html;

$.comp("try1button", try1buttonfunc);
