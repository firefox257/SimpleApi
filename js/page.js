import {$global,$q, $qa, $comp, $msgc, $fastpath} from "./tools.js";
const css = `
	.page
	{
		
		padding: 1mm;
		background-color: rgba(255, 255, 255, 0.1);
		margin: 0;
		position:absolute;
		top:${$global.topMenuHeight + 2}mm;
		left: ${$global.sideMenuWidth + 0.7}mm;
		display:inline-block;
		
		bottom: 0;
		right: 0;
	}
	.page.hide
	{
		display:none;
	}
	.page.show
	{
		display:block;
	}

`;
const html =`
<div tieinner tieclass="stylecss">
	
</div>
`;
function page()
{
	
	var msgchandler = function(atid)
	{ 
		if(at.attributes.id == atid)
		{
			at.stylecss = "page show";
		}
		else
		{
			at.stylecss = "page hide";
		}
	}
	
	var at = {
		attributes: 
		{
			id: undefined,
			group: undefined,
			show: false
		},
		stylecss: "page hide",
		init()
		{
			$msgc.subscribe(`${at.attributes.group} unselect all`, msgchandler);
			if(at.attributes.show ==="true")
			{
				at.stylecss = "page show";
			}
		}, 
		destruct()
		{
			console.log("page destruct");
			$msgc.unsubscribe(`${at.attributes.group} unselect all`, msgchandler);
		}
	};
	
	return at;
}
page.css = css;
page.html = html;

$comp("page", page);
