import React from 'react';

import { Grid, GridList, GridListTile } from '@material-ui/core';
import ModalImgurImage from '../../../../Modals/ImgurImage';
import { useState } from 'react';


const BodyImgur = ({data}) => {

    const [modal, setModal] = useState({open: false, data: {}});

    if (data.length === 0)
        return (<div />);

    return (
        <Grid>
            <GridList cellHeight={160} cols={3}>
                { data.map((tile, index) => {
                    if (tile && (tile.type ? (tile.type === "image/jpeg") : (tile.images[0].type === "image/jpeg"))) {
                        return (
                            <GridListTile onClick={() => setModal({open: true, data: tile})} key={`${tile.id}-${index}`} cols={1}>
                                <img src={tile.type ? tile.link : tile.images[0].link} alt={""} />
                            </GridListTile>
                        );
                    } else {
                        return (<div key={`${tile.id}-${index}`} style={{height: "0px", width: "0px", padding: "0px"}}/>);
                    }
                })
                }
            </GridList>
            <ModalImgurImage open={modal} setClose={() => setModal({open: false, data: {}})} />
        </Grid>
    );
};

export default BodyImgur;