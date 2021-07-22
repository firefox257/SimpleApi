import {$q, $qa, $comp, $msgc, $fastpath} from "./tools.js";


const css =`


`;

const html = `

<span>
title 2 here: <span tie="title:innerHTML"></span>
<input tie="value:value" type ="text" trackevents="oninput"></input>
<div tieinner>
</div>
</span>

`;


function try2()
{
	
	var at = {
		
		title:"Hiasdfasdf",
		value: "text here",
		attributes: {
			
			get group()
			{
				return "";
			},
			set group(v)
			{
				console.log("set group " + v);
			}
		},
		beforeinit()
		{
			console.log("before init try2");
		},
		init()
		{
			console.log("init try2");
			at.tracker.value.push(function(v)
			{
				console.log(v);
			});
		}
	};
	
	
	return at;
}


try2.css = css;
try2.html = html;



$comp("try2", try2);




