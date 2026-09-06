import React, {useState} from 'react';
import { makeStyles } from '@material-ui/core/styles';
import GridList from '@material-ui/core/GridList';
import GridListTile from '@material-ui/core/GridListTile';
import { Grid } from '@material-ui/core';
// import tileData from './tileData.json';
import ExpandMoreIcon from '@material-ui/icons/ExpandMore';
import IsModale from './Modale';
//import getPicture from '../../getPicture';
//import $ from 'jquery';
// import { useEffect } from 'react';

const useStyles = makeStyles(theme => ({
  root: {
    display: 'flex',
    flexWrap: 'wrap',
    justifyContent: 'space-around',
    overflowY: 'auto',
    overflowX: 'hidden',
    width: "100%",
    height: "100%",
    // backgroundColor: theme.palette.background.paper,
  },
  gridList: {
      height: ""
    // width: "100%",
    // height: "100%",
  },
  test: {

    '& .MuiGridListTile-tile': {
        borderRadius: '3px'
    },
    '& .MuiGridListTile-imgFullWidth': {
        opacity: 0.8,        
    },
        '&:hover': {
            zIndex: 1,
            opacity: 1,
            '& .MuiGridListTile-imgFullWidth': {
            opacity: 1,
            },
        }
    }
}));

export default function ImageGridList({isData, refreshPage}) {
    const classes = useStyles();
    //const [valueLimit, setValueLimit] = useState(15);
    const [isOpened, setOpened] = useState({state: false, data: {}});
    // const [isData, setData] = useState([]);

//     useEffect(() => {
// const toto = () => {
// 	var pictures = [];
// 	var url = "https://api.nasa.gov/planetary/apod?api_key=XXXXXXXX_NASA_APOD_API_KEY_REDACTED_XXXX&date=";

// 	for (let i = 0, date = new Date(); i < 2000; i++) {
// 		$.getJSON(url + date.toJSON().substr(0, 10), function(data) {
// 			if (data.media_type.localeCompare("image") === 0)
// 				pictures.push(data);
// 			else
// 				i -= 1;
// 		});
// 		date.setDate(date.getDate() - 1);
// 	}
//         setData(pictures);
//         console.log("????", pictures);
//         if (isData) {}
//     }
//     toto();
//         // setData(getPicture());
//     // eslint-disable-next-line react-hooks/exhaustive-deps
//     }, []);

    const handleClick = () => {
        //setValueLimit(valueLimit + 15);
        refreshPage();
    }

    const Modale = (tile) => {
        setOpened({state: true, data: tile});
    }

    // if (isData.length == 0) return (<div></div>)
console.log(isData, isData.length);
  return (
    <div>
    <div className={classes.root}>
        <Grid item>
            <GridList cellHeight={260} className={classes.gridList} cols={3}>
                {isData.data.map((tile, index) => (
                    index < isData.count ?
                    <GridListTile key={`${tile.id} + ${index}`} cols={1} onClick={() => Modale(tile)} className={classes.test}>
                    {/* {console.log("object")} */}
                            <img src={tile.url} alt="" />
                        </GridListTile>
                    :
                    <div key={`${index}`} style={{height: '0px', width: '0px'}} />
                ))}
            </GridList>
        </Grid>
        <Grid onClick={handleClick} style={{height: '80px', paddingTop: '45px', paddingBottom: '5px'}}>
            <a href="#" className="myButton">
                <ExpandMoreIcon style={{fontSize: "3rem"}}/>
            </a>
        </Grid>
    </div>
        <IsModale isOpened={isOpened} handleClose={() => setOpened({state: false, data: {}}) } />
    </div>
  );
}