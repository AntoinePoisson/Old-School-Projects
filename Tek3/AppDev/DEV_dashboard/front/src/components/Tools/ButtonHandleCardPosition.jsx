import React, { useState } from 'react';

import { Grow, Menu, MenuItem, IconButton, Divider } from '@material-ui/core';

import KeyboardArrowLeftIcon from '@material-ui/icons/KeyboardArrowLeft';
import KeyboardArrowRightIcon from '@material-ui/icons/KeyboardArrowRight';
import KeyboardArrowUpIcon from '@material-ui/icons/KeyboardArrowUp';
import KeyboardArrowDownIcon from '@material-ui/icons/KeyboardArrowDown';
import MoreVertIcon from '@material-ui/icons/MoreVert';
import AddIcon from '@material-ui/icons/Add';
import RemoveIcon from '@material-ui/icons/Remove';
import DeleteIcon from '@material-ui/icons/Delete';

import useStyles from '../../styles/ButtonHandleCardPosition';


const ButtonHandleCardPosition = ({index, list, setList}) => {

    const classes = useStyles();

    const [anchorEl, setAnchorEl] = useState(null);

    const changeLeft = () => {
        if (index === 0)
            return;
        var tmp = list;
        var save = list[index - 1];
        tmp[index - 1] = list[index];
        tmp[index] = save;
        setList([...tmp]);
    };

    const changeRight = () => {
        if (index === (list.length - 1))
            return;
        var tmp = list;
        var save = list[index + 1];
        tmp[index + 1] = list[index];
        tmp[index] = save;
        setList([...tmp]);
    };

    const changeUp = () => {
        var i = -1;
        var count = 0;
        var tmp = list;

        for (let el of list) {
            i += 1;
            if (i <= index)
                continue;
            count += el.size;
            if (count >= 12)
                break;
        }
        if ((count < 12) || (i >= list.length)) {
            let save = list[index]
            tmp.splice(index, 1);
            tmp.push(save);
        } else {
            var save = list[i];
            tmp[i] = list[index]
            tmp[index] = save
        }
        setList([...tmp]);
    };

    const changeDown = () => {
        var i = list.length - 1;
        var count = 0;
        var tmp = list;
        var inverse = list;

        for (let el of inverse.reverse()) {
            i -= 1;
            if (index <= i)
                continue;
            count += el.size;
            if (count >= 12)
                break;
        }
        inverse.reverse()
        if ((count < 12) || (i <= 0)) {
            let save = list[index]
            tmp.splice(index, 1);
            tmp.unshift(save);
        } else {
            var save = list[i];
            tmp[i] = list[index]
            tmp[index] = save
        }
        setList([...tmp]);
    };

    const changeSizeUp = () => {
        var tmp = list;

        if (list[index].size === 4) {
            tmp[index].size = 6;
            setList([...tmp]);
        } else if (list[index].size === 6) {
            tmp[index].size = 12;
            setList([...tmp]);
        }
    };

    const changeSizeDown = () => {
        var tmp = list;

        if (list[index].size === 6) {
            tmp[index].size = 4;
            setList([...tmp]);
        } else if (list[index].size === 12) {
            tmp[index].size = 6;
            setList([...tmp]);
        }
    };

    const deleteElement = () => {
        var tmp = list;

        tmp.splice(index, 1);
        setList([...tmp]);
    }


    return (
        <div style={{display: "inline-block"}}>
            <IconButton
                className={classes.tierButton}
                onClick={(event) => setAnchorEl(event.currentTarget)}
                size="medium">
                <MoreVertIcon />
            </IconButton>
            <Menu
                className={classes.menu}
                id="simple-menu"
                anchorEl={anchorEl}
                keepMounted
                anchorOrigin={{
                    vertical: 'top',
                    horizontal: 'center',
                }}
                transformOrigin={{
                    vertical: 'top',
                    horizontal: 'center',
                }}
                open={Boolean(anchorEl)}
                onClose={() => setAnchorEl(null)}
                TransitionComponent={Grow}
                style={{borderRadius: "18px"}}>
                <MenuItem disabled={index === 0} className={classes.menuItem} onClick={changeLeft}><KeyboardArrowLeftIcon /></MenuItem>
                <MenuItem disabled={index === 0} className={classes.menuItem} onClick={changeDown}><KeyboardArrowUpIcon /></MenuItem>
                <MenuItem disabled={index === (list.length - 1)} className={classes.menuItem} onClick={changeUp}><KeyboardArrowDownIcon /></MenuItem>
                <MenuItem disabled={index === (list.length - 1)} className={classes.menuItem} onClick={changeRight}><KeyboardArrowRightIcon /></MenuItem>
                <Divider className={classes.menuDividerItem} orientation="vertical" style={{backgroundColor: "black"}} />
                <MenuItem disabled={list[index].size === 12} className={classes.menuItem} onClick={changeSizeUp}><AddIcon /></MenuItem>
                <MenuItem disabled={list[index].size === 4} className={classes.menuItem} onClick={changeSizeDown}><RemoveIcon /></MenuItem>
                <MenuItem className={classes.menuItem} onClick={deleteElement}><DeleteIcon /></MenuItem>
            </Menu>
        </div>
    );
};

export default ButtonHandleCardPosition;