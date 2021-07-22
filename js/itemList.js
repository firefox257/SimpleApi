import {$} from "./tools.js";

const css = `



`;

const html = `

<div>
	<span  tie="text:innerHTML" tieevents="onclick:onclick"></span><span tieevents="removeme:onclick"> remove</span>
</div>

`;
function itemList()
{
	var at = {
		attributes: {
			
			get text()
			{
				return at.text;
			},
			set text(v)
			{
				at.text = v;
			},
			onclick: undefined
		},
		text: "",
		onclick(e)
		{
			if(at.attributes.onclick) at.attributes.onclick(at.attributes.text);
		},
		removeme(e)
		{
			$.removeComp(at);
		},
		init()
		{
			
		},
		destruct()
		{
			console.log("destruct " + at.text);
		}
		
	};
	
	return at;
}
itemList.css = css;
itemList.html = html;


$.comp("itemList", itemList);
