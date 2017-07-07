import { Config } from '../config/config.type';
export default class Frame {
    config: Config;
    constructor(config: Config);
    init(): void;
}
