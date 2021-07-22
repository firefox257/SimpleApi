import "./topMenuItem.js";
import "./page.js"
import "./itemList.js"
import {$, $global, $q, $qa, $comp, $msgc, $fastpath} from "./tools.js" 

const css = `

	body
	{
		background-color: #333;
		font-size: 3.5mm;
		color:#ddd;
	}
	.mainapp
	{
		position: absolute;
		top:0;
		left:0;
		width: 100vw;
		height: 100vh;
	}	
	.topMenu
	{
		position: absolute;
		top: 0;
		left: 0;
		width: 100vw;
		height: ${$global.topMenuHeight}mm;
		border-bottom: 0.7mm solid #ffbb44;
		padding: 0 0 1mm 0;
	}
	.sideMenu
	{
		position: absolute;
		top: ${$global.topMenuHeight + 2}mm;
		left: 0;
		bottm: 0;
		width: ${$global.sideMenuWidth}mm;
		border-right: 0.5mm solid #666;
		padding 0 1mm 0 0;
	}
	.mainSection
	{
		position:absolute;
		top:${$global.topMenuHeight + 0.7}mm;
		left:${$global.sideMenuWidth + 0.7}mm;
		right: 0;
		bottom: 0;
		width: 100%;
		height: 100%;
	}
`;
const html = `
<div class = "fullScreen">
	<div class = "topMenu">
		<comp tietype="topMenuItem" text = "Start" selected = "true"  id="starttopmenu" group="topmenu" tieevents="startClick:onclick"></comp>
		<comp tietype="topMenuItem" text = "View" selected = "false" id="viewstopmenu" group="topmenu" tieevents="viewClick:onclick"></comp>	
		<comp tietype="topMenuItem" text = "Edit" selected = "false" id="edittopmenu" group="topmenu" ></comp>
		
	
	</div>
	<div class = "sideMenu">
	</div>
	
	<comp tietype="page" id="starttopmenu" group="topmenu"  show = "true">
		<input type="text" tie="in1:value" trackevents="oninput"/>
	</comp>
	<comp tietype= "page" id="viewstopmenu" group="topmenu" show = "false">
		view page
		<input type="text" tie ="in2:value" tieevents ="input2:oninput" ></input>
	</comp>	
	<comp tietype= "page" id="edittopmenu" group="topmenu" show = "false">
		edit page
		<div tiedom = "itemsDom"></div>
	</comp>	
</div>
`;

function mainapp()
{
	
	var at = {
		itemsDom: undefined,
		startClick(e)
		{
			console.log("start clicked");
		},
		viewClick(e)
		{
			console.log("view clicked");
		},
		in1: "start",
		getitemselected(item)
		{
			alert(item);
		},
		in2: "here1asdf",
		input2(e)
		{
			console.log(at.in2);
		},
		init()
		{
			at.tracker.in1.push(function(v)
			{
				console.log(at.in1);
			});
		},
		afterinit()
		{
			for(var i = 1; i < 10; i++)
			{
				$.appendComp(at, at.itemsDom, {
					tietype: "itemList",
					text: "hi there" + i,
					tieevents: "getitemselected:onclick"
				});
			}
		}
	};
	
	
	return at;
}
mainapp.css = css;
mainapp.html = html;

$comp("mainapp", mainapp);
