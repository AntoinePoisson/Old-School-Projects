import React, { useState } from 'react';
import AppBar from './Components/AppBar/MainComponent'
import ImageGridList from './Components/GridList/MainComponent'
import AHAHAHAHA from './test.json'
import "./styles.css"


export default function App() {

   // const [isCount, setCount] = useState(0);
   const [isdata, setData] = useState({data : AHAHAHAHA, count: 24});

   // componentDidMount = () => { this.refreshPage() }

   const refreshPage = () => {
      setData({...isdata, count: isdata.count + 48});
   //    var pictures = [];
   //    var url = "https://api.nasa.gov/planetary/apod?api_key=XXXXXXXX_NASA_APOD_API_KEY_REDACTED_XXXX&date=";
   //   var date = new Date();
  
   //    date.setDate(date.getDate() - isCount);
   //    for (let i = 0; i < 10; i++) {
   //      $.getJSON(url + date.toJSON().substr(0, 10), function(data) {
   //         if (data.media_type.localeCompare("image") === 0)
   //         pictures.push(data);           
   //         else
   //            i = i - 1;
   //      });
   //      date.setDate(date.getDate() - 1);
   //    }
   //    console.log("picture ?", pictures);
   //    console.log("tessssssstttttt ?", [...isdata, ...pictures]);
   //    // console.log("okkkkk ?", data);
   //    setCount(isCount + 20);
   //    setData([...isdata, ...pictures]);
      // setData(pictures);
   }
console.log(isdata)
      // if (data.length === 0)
      //    return (<div/>)
      return (
         <div>
            <AppBar />
            <div style={{ overflow: 'auto', width: "95vw", height: "85vh", margin: "auto", paddingTop: "30px" }}>
               <ImageGridList isData={isdata} refreshPage={() => refreshPage()} />
            </div>
         </div>
      );
}